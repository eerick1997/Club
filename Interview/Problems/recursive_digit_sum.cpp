#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

lli digit_sum( string n ) {
    lli ans = 0;
    if( n.size() == 1 )
        return stol( n );

    for( char c : n )
        ans += c - '0';
    
    return digit_sum( to_string( ans ) );
}

int main() {
    string n;
    lli k, ans;
    cin >> n >> k;
    ans = digit_sum( n );
    cout << digit_sum( to_string(ans * k) ) << endl;
    return 0;
}