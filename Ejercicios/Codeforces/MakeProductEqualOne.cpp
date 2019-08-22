#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    int n;
    lli negative = 0, positive = 0, zeros = 0, v, ans = 0;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> v;
        if( v == 0 )
            ans++, zeros++;
        else if( v < 0 ){
            ans += abs( v + 1 );
            negative++;
        } else {
            positive++;
            ans += abs( v - 1 );
        }
    }
    //If negative numbers is odd
    if( positive == 0 && zeros == 0){    
        if( negative % 2 != 0 )
            ans += 2;
    } else if( negative % 2 != 0 && zeros == 0 ){
        ans += 2;
    }

    cout << ( ans ) << endl;
    
    return 0;
}