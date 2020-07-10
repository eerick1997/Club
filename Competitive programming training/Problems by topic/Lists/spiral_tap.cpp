#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int64_t size, spiral, i, j;
    int max, min, r_size, count;
    pair< int64_t, int64_t > ans;

    while( cin >> size >> spiral and size and spiral ) {
        ans = {0, 0};
        i = 1, j = 0;

        while( i * i < spiral )
            i += 2, j++;
        
        max = size / 2 + 1 + j;
        min = size / 2 + 1 - j;
        r_size = max - min;

        count = i * i;

        if( spiral > 1 ) {

            if( spiral >= count - r_size ) {
                for( int row = max; row >= min; row--, count-- )
                    if( spiral == count )
                        ans = { row, max };
            } else if( spiral >= count - 2 * r_size ) {
                count -= r_size;
                for( int col = max; col >= min; col--, count-- )
                    if( spiral == count )
                        ans = { min, col };
            } else if( spiral >= count - 3 * r_size ) {
                count -= 2 * r_size;
                for( int row = min; row <= max; row++, count-- )
                    if( spiral == count )
                        ans = { row, min };
            } else {
                count -= 3 * r_size;
                for( int col = min; col <= max; col++, count-- )
                    if( spiral == count )
                        ans = { max, col };
            }
        } else 
            ans.first = ans.second = size / 2 + 1;

        cout << "Line = " << ans.first << ", column = " << ans.second << ".\n";
    }
    return 0;
}