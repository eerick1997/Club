#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int32_t test_cases, n, ans = 0;
    vector< int32_t > a;
    cin >> test_cases;
    while( test_cases-- ) {
        ans = 0;
        cin >> n;
        a.resize( n );
        for( int32_t i = 0; i < n; i++ )
            cin >> a[ i ];

        for( int32_t i = n - 1 ; i >= 0; i-- ) {
            if( a[ i ] == ( i + 1 ) )
                continue;
            else if( ( i - 1 ) >= 0 && a[ i - 1 ] == ( i + 1 ) )
                swap( a[ i - 1 ], a[ i ] ), ans++;
            else if( ( i - 2 ) >= 0 && a[ i - 2 ] == ( i + 1 ) ){
                swap( a[ i - 1 ], a[ i ] );
                swap( a[ i - 2 ], a[ i ] );
                ans += 2;
            } else {
                ans = -1;
                break;
            }
        }
        if( ans < 0 )
            cout << "Too chaotic \n";
        else
            cout << ans << endl;
    }
    return 0;
}