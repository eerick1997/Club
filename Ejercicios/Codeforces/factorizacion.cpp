#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n, k;
    cin >> n >> k;

    vector< lli > lowestPrime( n + 1, 1 );
    lowestPrime[ 0 ] = lowestPrime[ 1 ] = 0;
    for( lli i = 2; i <= n; i++ ) 
        lowestPrime[ i ] = ( i & 1 ? i : 2 );

    lli limit = sqrt( n );
    for( lli i = 3; i <= limit; i += 2 )
        if( lowestPrime[ i ] == i )
            for( lli j = i * i; j <= n; j += 2 * i )
                if( lowestPrime[ j ] == j )
                    lowestPrime[ j ] = i;
    
    lli m = n;
    vector< lli > factors;
    while( m > 1 ){
        lli p = lowestPrime[ m ];
        factors.push_back( p );
        m /= p;
    }
    
    int n_factors = factors.size();
    if( n_factors < k ){
        cout << -1 << endl;
        return 0;
    } else {
        for( int i = 0; i < k - 1; i++ )
            cout << factors[ i ] << " ";
        
        int product = 1;
        for( int i = k - 1; i < n_factors; i++ )
            product *= factors[ i ];
        cout << product << endl;
    }
    return 0;
}