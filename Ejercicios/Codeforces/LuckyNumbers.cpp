#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli binExp( lli b, lli e ){
    lli ans = 1;
    while( e ){
        if( e & 1 )
            ans *= b;
        e >>= 1;
        b *= b;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    int n;
    lli ans = 0;
    cin >> n;
    
    for( int i = 1; i <= n; i++ )
        ans += binExp( 2, i );

    cout << ans << endl;
    return 0;
}