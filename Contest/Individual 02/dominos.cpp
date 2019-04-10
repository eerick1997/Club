#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){

    lli l, r, a, b;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if( a % 2 != 0 )
            l++;
        if( b % 2 != 0)
            r++;
    }
    
    if(n == 1){
        if(l > 0 || r > 0)
            cout << -1 << endl;
    } else {

        if( l == n && r == n)
            cout << -1 << endl;
        else if( l === r){
            cout << 0;
        }
            cout << ( ( (l + r) % 2 == 0) ? 0 : 1 ) << endl;
    }

    return 0;
}