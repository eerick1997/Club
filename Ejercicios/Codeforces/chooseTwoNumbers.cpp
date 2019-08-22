#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, v;
    set< int > A, B;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> v;
        A.insert( v );
    }
    cin >> m;
    for( int i = 0; i < m; i++ ){
        cin >> v;
        B.insert( v );
    }
    for( auto a : A ){
        for( auto b : B ){
            if( A.count( a + b ) == 0 && B.count( a + b ) == 0 ){
                cout << a << " " << b << endl;
                exit( 0 );
            }
        }
    }
    return 0;
}