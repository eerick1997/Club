#include <bits/stdc++.h>

using namespace std;

using lli = long long int;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    string s;
    lli A = 0, B = 0, C = 0;
    cin >>  s;

    for( char c : s ) {
        if( c == 'a' ){
            A++;
            if( B > 0 or C > 0 ){
                cout << "NO" << endl;
                return 0;
            }
        } else if( c == 'b' ){
            B++;
            if( A == 0 or C > 0 ){
                cout << "NO" << endl;
                return 0;
             }
        } else {
            C++;
            if( A == 0 or B == 0 ){
                cout << "NO" << endl;
                return 0;
            }
        }

    }

    if( ( A > 0 && B > 0 ) and ( C == A or C == B ) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}