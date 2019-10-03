#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli l, r;
    cin >> l >> r;
    cout << "YES" << endl;
    for( lli i = l; i <= r; i += 2 ){
        cout << i << " " << (i + 1) << endl;
    }
}
