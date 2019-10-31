#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    int t;
    lli n, k, ans = 0, res = 0;

    cin >> t;
    while( t-- ){
        ans = 0;
        cin >> n >> k;
        while( n > 0 ){
            if( ( n % k ) != 0 )
                ans += (n % k), n -= ( n % k ), n /= k, ans++;
            else 
                n /= k, ans++;
        }
        cout << (ans - 1) << endl;
    }
    
    

}