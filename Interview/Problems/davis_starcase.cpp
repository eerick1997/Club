#include <bits/stdc++.h>
#define MOD 10000000007

using namespace std;
using lli = long long int;
vector< lli > DP;

lli step_perms( lli height ) {

    if( height < 0 )
        return 0;

    if( height == 0 )
        return 1;

    if( DP[ height ] != -1 )
        return DP[ height ];

    return DP[ height ] = ( step_perms( height - 1 ) % MOD + step_perms( height - 2 ) % MOD + step_perms( height - 3 ) % MOD ) % MOD;
}

int main() {
    lli stairs, height;
    cin >> stairs;
    while( stairs-- ) {
        cin >> height;
        DP.assign( 37, -1 );
        cout << step_perms( height ) << endl;
    }

}