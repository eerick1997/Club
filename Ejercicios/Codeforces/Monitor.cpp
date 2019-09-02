#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli a, b, x, y, begin, end, middle, GCD, ans = 0;
    cin >> a >> b >> x >> y;
    GCD = __gcd(x, y);
    x /= GCD;
    y /= GCD;
    lli AB = max(a, b);
    lli XY = max(x, y);
    begin = 1;
    end = AB / XY;
    while( begin <= end ){
        middle = ( begin + end ) / 2;

        if( x * middle <= a && y * middle <= b ){
            ans = middle;
            begin = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    cout << x * ans << " " << y * ans << endl;
    return 0;
}