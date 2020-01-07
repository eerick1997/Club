#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int16_t arr[ 6 ][ 6 ];
    int16_t hourglass_sum = 0, maximum_sum = -100;
    for( int16_t i = 0; i < 6; i++ )
        for( int16_t j = 0; j < 6; j++ )
            cin >> arr[ i ][ j ];

    for( int16_t i = 1; i < 5; i++ ) {
        for( int16_t j = 1; j < 5; j++ ) {
            hourglass_sum = 0;
            for( int16_t k = -1; k <= 1; k++ ) {
                for( int16_t l = -1; l <= 1; l++ ) {
                    int16_t ii = i + k, jj = j + l;
                    if( ! ((k == 0 && l == -1) || ( k == 0 && l == 1 ) ) )
                        hourglass_sum += arr[ ii ][ jj ];
                }
            }
            maximum_sum = max( maximum_sum, hourglass_sum );
        }
    }
    cout << maximum_sum << endl;
    return 0;
}