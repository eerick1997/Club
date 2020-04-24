#include <bits/stdc++.h>

using namespace std;

using lli = long long int;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli n, MAX = -1;
    vector< lli > numbers( 1001, 0 );
    cin >> n;

    for( lli i = 0, buffer = 0; i < n; i++ ) {
        cin >> buffer;
        numbers[ buffer ]++;
    }

    for( auto e : numbers )
        MAX = max( MAX, e );

    cout << n - MAX << endl;
    return 0;
}