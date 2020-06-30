#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    map< char, double > characters;
    int tests, paid_characters, lines;
    char character;
    double value, ans;
    string buffer;
    cout.precision(2);
    cin >> tests;
    while( tests-- ) {
        characters.clear();
        ans = 0;
        cin >> paid_characters;
        while( paid_characters-- ) {
            cin >> character >> value;
            characters[ character ] = value;
        }
        cin >> lines;
        cin.ignore();
        while( lines-- ) {
            getline( cin, buffer );
            for( char c : buffer )
                ans += characters[ c ];
        }
        cout << fixed << (ans / 100) << "$" << endl;
    }

}