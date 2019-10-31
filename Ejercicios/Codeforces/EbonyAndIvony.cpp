#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli a, b, c;
    cin >> a >> b >> c;
    
    for( lli i = 0; i <= 10000; i++ ){
        for( lli j = 0; j <= 10000; j++ ){
            if( ( ( a * i ) + ( b * j ) ) == c ){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
    return 0;
}