#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli digitProduct( string S ){

    lli ans = 0;
    for( auto c : S )
        ans += ( c - '0' );
    
    if( ans > 9 )
        return digitProduct( to_string( ans ) );
    return ans;
}

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    lli RES = 1;
    int A, B, P;
    string As, Bs, Ps;
    cin >> A >> B >> P;
    cin >> As >> Bs >> Ps;
    auto it = find( Ps.begin(), Ps.end(), '*' );

    RES = digitProduct( to_string( digitProduct( As ) * digitProduct( Bs ) ) );

    for( char i = '1'; i <= '9'; i++ ){
        (*it) = i;
        if( digitProduct( Ps ) == RES ){
            cout << i << endl;
            break;
        }
    }
    return 0;
}