#include <bits/stdc++.h>

using namespace std;
using Double = long double;
struct assasain{
    Double dead;
    Double alive;
    assasain(){ dead = 0.0, alive = 1.0; }
};

int main() {
    int n, m, from, to;
    Double p;
    vector< assasain > prob;
    cin >> n >> m;
    prob.resize( n + 1 );
    cout << fixed << setprecision( 10 );
    for( int i = 0; i < n; i++ ) {
        cin >> from >> to >> p;

        if( prob[ to ].dead == 1.0 and prob[ from ].dead == 1.0 )
            continue;

        //prob[ to ].alive *= //prob[ from ].alive * ( 1 - p ) + prob[ from ].dead;
        prob[ to ].dead += prob[ to ].alive * prob[ from ].alive * p;
        prob[ to ].alive = 1 - prob[ to ].dead;
        
    }

    for( int i = 1; i <= n; i++ ) {
        cout << prob[ i ].alive << " \t " << prob[ i ].dead << endl;
    }
}