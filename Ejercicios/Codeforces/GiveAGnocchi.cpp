#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int LIMIT = 2000000;

vector< lli > isPrime;

void primesSieve(lli n){

	isPrime.resize( n + 1, 1 );
    for( lli i = 4; i <= n; i += 2 )
        isPrime[ i ] = 2;
    
    for( lli i = 3; i <= n; i += 2 )
        if( isPrime[ i ] == 1 )
            for( lli j = i * i; j <= n; j += 2 * i )
                if( isPrime[ j ] == 1 )
                    isPrime[ j ] = i;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int n, k;
    cin >> n >> k;
    primesSieve( LIMIT );
    lli i;

    for( i = n; i <= LIMIT; i++ ){
        if( isPrime[ i ] > n ){
            if( k == 1 ){
                cout << i << endl;
                return 0;
            }
            k--;
        }
    }
    return 0;
}