#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int Y, W, MAX, DIFF, GCD;
    cin >> Y >> W;
    MAX = max( Y, W );
    DIFF = abs( MAX - 6 ) + 1;
    GCD = __gcd( DIFF, 6 );
    if( DIFF == 0 )
        cout << "0/1" << endl;
    else if( DIFF == 6 )
        cout << "1/1" << endl;
    else
        cout << ( DIFF / GCD ) << "/" << ( 6 / GCD ) << endl;
    return 0;
}