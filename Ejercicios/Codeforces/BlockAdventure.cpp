#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    //n = n columns
    //m = blocks in the bag
    //k = non-negative integer
    ios::sync_with_stdio( 0 );
    cout.tie( 0 );
    cin.tie( 0 );
    string ans;
    int t, n, m, k;
    cin >> t;
    while( t-- ){
        ans = "YES";
        cin >> n >> m >> k;
        vector< int > columns( n, 0 );
        for( int i = 0; i < n; i++ )
            cin >> columns[ i ];

        for( int i = 0; i < n - 1; i++ ) {
            int current_column = columns[ i ];
            int next_column = columns[ i + 1 ];
            int difference = abs( current_column - next_column );

            m += current_column;
            if( next_column - k >= 0 ){
                if( m - ( next_column - k ) >= 0 )
                    m -= next_column - k;
                else {
                    ans = "NO";
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}