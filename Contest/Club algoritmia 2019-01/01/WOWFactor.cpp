#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int n;
vector< lli > Vs_left, Vs_right;
string s;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli vv_left = 0, vv_right = 0, ans = 0;
    cin >> s;
    n = s.size();
    Vs_left.assign( n, 0 );
    Vs_right.assign( n, 0 );

    for( int i = 0, c = 0; i < n - 1; i++ ){
        if( s[ i ] == 'v' && s[ i + 1 ] == 'v')
            c++;
        Vs_left[ i ] = c;
    }

    for( int i = n - 1, c = 0; i >= 1; i-- ){
        if( s[ i ] == 'v' && s[ i - 1 ] == 'v')
            c++;
        Vs_right[ i ] = c;
    }

    for( int i = 0; i < n; i++ ){
        if( s[ i ] == 'o' )
            ans += ( Vs_right[ i ] * Vs_left[ i ] );
    }

    cout << ans << endl;
}