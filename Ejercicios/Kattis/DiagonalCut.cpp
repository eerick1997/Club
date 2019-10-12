#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
//If you want to find the pattern maybe is better if you try to make some draws. My recommendation see what
//happens if you have a grid of 1 x 2, 1 x 3, 1 x 4, 2 x 2, 3 x 3, 2 x 6, 6 x 10

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    
    lli M, N, GCD = 0;
    cin >> M >> N;
    GCD = __gcd( M, N );
    if( ( (M / GCD) & 1 ) && ( (N / GCD) & 1 ) ){
        cout << GCD << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}