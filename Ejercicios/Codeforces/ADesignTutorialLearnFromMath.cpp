#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n;
    cin >> n;
    if( !(n & 1) )
        cout << 4 << " " << ( n - 4 ) << endl;
    else 
        cout << 9 << " " << ( n - 9 ) << endl;
    return 0;
}