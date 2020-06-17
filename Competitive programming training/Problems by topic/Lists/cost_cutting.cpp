#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int t;
    vector< int > salary( 3 );
    cin >> t;
    for( int i = 1; i <= t; i++ ){
        cin >> salary[ 0 ] >> salary[ 1 ] >> salary[ 2 ];
        sort( begin( salary ), end( salary ) );
        cout << "Case " << i << ": " << salary[ 1 ] << endl;
    }

}