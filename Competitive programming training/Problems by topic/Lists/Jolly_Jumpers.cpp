#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int n, last, current;
    vector< bool > jolly;

    bool flag = true;
    while( cin >> n and n ) {
        
        jolly.clear();
        jolly.assign( 3000, false );

        cin >> current;
        for( int i = 1; i < n; i++ ) {
            last = current;
            cin >> current;
            jolly[ abs( last - current ) ] = true;
        }

        flag = true;
        for( int i = 1; i < n; i++ )
            flag &= jolly[ i ];

        cout << ( flag ? "Jolly" : "Not jolly" ) << endl;

    }

}