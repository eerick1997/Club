#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli lowestPrime( lli n ){

    for( lli d = 2; d * d <= n; d++ ){
        if( ( n % d ) == 0 )
            return d;
    }
    return n;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli n, d, count = 0;
    cin >> n;

    if( ( n & 1) ){
        d = lowestPrime( n );
        count = (n - d) / 2;
        cout << ( count + 1 ) << endl;
    } else {
        cout << n / 2 << endl;
    }

    
    return 0;
}