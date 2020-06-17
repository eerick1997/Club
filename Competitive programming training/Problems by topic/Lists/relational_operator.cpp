#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    
    int t;
    lli a, b;
    cin >> t;
    while( t-- ) {
        cin >> a >> b;
        if( a > b )
            cout << ">" << endl;
        else if( a < b )
            cout << "<" << endl;
        else 
            cout << "=" << endl;
    }
    return 0;
}