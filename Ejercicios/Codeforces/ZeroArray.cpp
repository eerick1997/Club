#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli n, v, ans = 0;
    cin >> n;
    while( n-- ){
        cin >> v;
        ans += ( v % 2 );
    }

    if( ans & 1 )
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;

}