#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int n;
    cin >> n;

    vector< int > lowestPrime( n + 1, 1 );
    lowestPrime[ 0 ] = lowestPrime[ 1 ] = 0;

    for( int i = 2; i <= n; i++ )
        lowestPrime[ i ] = ( i & 1 ? i : 2 );
    
    int limit = sqrt( n );
    for( int i = 3; i <= limit; i += 2 )
        if( lowestPrime[ i ] == i )
            for( int j = i * i; j <= n; j += 2 * i )
                if( lowestPrime[ j ] == j )
                    lowestPrime[ j ] = i;
    
    int m = n;
    vector< int > factors;
    while( m > 1 ){
        int p = lowestPrime[ m ];
        factors.push_back( p );
        m /= p;
    }

    return 0;
}