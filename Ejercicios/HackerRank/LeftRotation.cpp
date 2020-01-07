#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int32_t n, d;
    vector< int32_t > a, aux;
    cin >> n >> d;
    a.resize( n );
    aux.resize( n );
    for( int32_t i = 0; i < n; i++ )
        cin >> a[ i ];

    for( int32_t i = 0; i < d; i++ )
        aux[ n - d + i ] = a[ i ];

    for( int32_t i = d; i < n; i++ )
        aux[ i - d ] = a[ i ];

    for( int32_t a_i : aux )
        cout << a_i << " ";

    cout << endl;
}