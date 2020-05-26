#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int prefix_length, cipher_length;
    string prefix, cipher_text, plain_text;

    cin >> prefix_length >> cipher_length;
    cin >> prefix >> cipher_text;

    for( int i = 0; i < cipher_length - prefix_length; i++ )
        plain_text += cipher_text[ i ];
    
    plain_text += prefix;

    for( int i = cipher_length - 1; i > prefix_length - 1; i-- )
        plain_text[ i - prefix_length ] = 'a' + ( 26 + cipher_text[ i ] - plain_text[ i ] ) % 26;

    cout << plain_text << endl;
    return 0;
}