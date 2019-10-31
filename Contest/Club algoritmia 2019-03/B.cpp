#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli t, n, ans, mod1, mod2, MIN;
    cin >> t;
    while( t-- ){
        MIN = INT64_MAX;
        ans = mod1 = mod2 = 0;

        cin >> n;
        
        for( int i = 0, v; i < n; i++ ){
            cin >> v;
            switch ( v % 3 ){
                case 0:
                    ans++;
                break;
                case 1:
                    mod1++;
                break;
                case 2:
                    mod2++;
                break;
            }
        }

        MIN = min( mod1, mod2 );

        ans += MIN;
        mod1 -= MIN;
        mod2 -= MIN;

        cout << (ans + ceil( mod1 / 3 ) + ceil( (mod2 * 2) / 6 ) ) << endl;
    }
    return 0;
}