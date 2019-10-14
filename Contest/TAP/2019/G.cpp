#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Gauss( lli n ){
    return ( (n * (n + 1)) / 2 );
}
int main(){
    int N;
    lli accumDiff = 0;
    cin >> N;
    vector< lli > group( N, 0 );
    for( int i = 0; i < N; i++ )
        cin >> group[ i ];

    for( int i = 1; i < N; i++ )
        accumDiff += abs( group[ 0 ] - group[ i ]);

    cout << accumDiff << endl;
    cout << Gauss( accumDiff ) << endl;

    cout << ( Gauss( accumDiff ) > group[ 0 ] ? "NO" : "SI" ) << endl;
    
}