#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    
    int t, point_x, point_y, residence_x, residence_y;
    while( cin >> t && t ) {
        cin >> point_x >> point_y;
        while( t-- ) {
            cin >> residence_x >> residence_y;
            if( residence_x == point_x or residence_y == point_y )
                cout << "divisa" << endl;
            else if( residence_x > point_x ) { 
                if( residence_y > point_y )
                    cout << "NE" << endl;
                else 
                    cout << "SE" << endl;
            } else {
                if( residence_y > point_y )
                    cout << "NO" << endl;
                else 
                    cout << "SO" << endl;
            }
        }

    }
    return 0;
}