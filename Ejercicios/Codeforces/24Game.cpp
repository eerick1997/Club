#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int n;
    cin >> n;
    if( n <= 3 )   
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if( n == 4 ){
            cout << "4 * 3 = 12\n";
            cout << "2 * 12 = 24\n";
            cout << "1 * 24 = 24\n";
        } else if( n == 5 ){
            cout << "5 * 4 = 20\n";
            cout << "2 - 1 = 1\n";
            cout << "3 + 1 = 4\n";
            cout << "4 + 20 = 24\n";
        } else if( !( n & 1 ) ){
            cout << "4 * 3 = 12\n";
            cout << "12 * 2 = 24\n";
            for( int i = n; i >= 5; i -= 2 )
                cout << i << " - " << i - 1 << " = " << 1 << endl;
            for( int i = 0; i < ( (n >> 1) - 1 ); i++ )
                cout << "24 * 1 = 24\n"; 
        } else {
            cout << "5 * 4 = 20\n";
            cout << "2 - 1 = 1\n";
            cout << "3 + 1 = 4\n";
            cout << "20 + 4 = 24\n";
            for( int i = n; i >= 6; i -= 2)
                cout << i << " - " << i - 1 << " = " << 1 << endl;
            for( int i = 0; i < ( ( n >> 1 ) - 2 ); i++ )
                cout << "24 * 1 = 24\n"; 
        }
    }
    return 0;
}