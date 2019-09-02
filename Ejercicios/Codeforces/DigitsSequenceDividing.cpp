#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int q, n;
    cin >> q;
    while( q-- ){
        string str;
        cin >> n >> str;
        if( n == 2 && str[ 0 ] >= str[ 1 ] )
            cout << "NO" << endl;
        else {
            cout << "YES\n" << 2 << endl;
            cout << str[ 0 ];
            str[ 0 ] = ' ';
            cout << str << endl;
        }
    }
    return 0;
}