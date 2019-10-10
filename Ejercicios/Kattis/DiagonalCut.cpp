#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
// 1000 = 200
// 1000 = 333
int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli M, N, ans = 0;
    cin >> M >> N;
    ans = __gcd( 2 * M, 2 * N );

    if( M == N )
        ans = M;
    else if( ( M % 2 == 0 ) || ( N % 2 == 0 ) )
        ans = 0;
    else 
        ans = ceil( ((double)ans) / 2.0 );

    cout << ans << endl;
    return 0;
}