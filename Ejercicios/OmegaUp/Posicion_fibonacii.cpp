#include <bits/stdc++.h>

using namespace std;
uint64_t FIB[ 100 ];

int find( uint64_t n ){
    FIB[ 0 ] = 0, FIB[ 1 ] = 1;;
    if( n == 1 )
        return 1;
    for( int i = 2; i <= 100; i++ ) {
        FIB[ i ] = FIB[ i - 1 ] + FIB[ i - 2 ];
        if( FIB[ i ] == n )
            return i;
        else if( FIB[ i ] > n )
            return -1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    uint64_t n;
    cin >> n;
    cout << find( n ) << endl;
    return 0;
}