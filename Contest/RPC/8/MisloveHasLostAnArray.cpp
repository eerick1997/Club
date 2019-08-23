#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio( 0 );
    cout.tie( 0 );
    cin.tie( 0 );
    int n, l, r, ans = 1, min = 0, max = 0;
    cin >> n >> l >> r;
    for( int i = 0; i < n; i++ ){
        if( i > (n - l) )
            ans *= 2;
        min += ans;
    }

    for( int i = 0, ans = 1; i < n; i++, r-- ){
        if( r > 0 )
            ans *= 2;
        max += ans;
    }

    cout << min << " " << max / 2 << endl;
    return 0;
}