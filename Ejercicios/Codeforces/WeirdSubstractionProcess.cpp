#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli a, b;
    cin >> a >> b;
    while( a > 0 && b > 0 ){

        if( ( a >= 2 * b ) )
            a %= (2 * b);
        else if( ( b >= 2 * a ) )
            b %= (2 * a);
        else 
            break;
    }
    cout << a << " " << b << endl;
}