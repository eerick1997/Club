#include <bits/stdc++.h>

using namespace std;

using lli = long long int;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli n, limit;
    cin >> n;

    cout << n / 2 << endl;
    if( ( n & 1 ) ) {
        for( lli i = 0; i < ( n / 2 - 1 ); i++ )
            cout << 2 << " ";
        cout << 3;
    } else {
        for( lli i = 0; i < ( n / 2 ); i++ )
            cout << 2 << " ";
    }
    cout << endl;
}