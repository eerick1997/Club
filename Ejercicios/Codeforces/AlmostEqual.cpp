#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main(){
    int n, m;
    cin >> n;
    vector< int > ans( 2 * n + 1, 0 );

    if( !(n & 1) )
        cout << "NO" << endl;
    else {
        m = n / 2;
        for( int i = 1, j = 2, k = 2 * n; i <= 2 * n; i++ ){
            //Is an odd index
            if( (i & 1) ){
                ans[ i ] = i;
            } else if( i <= n ){
                ans[ i ] = k - ( 2 * ( --m ) );
            } else {
                ans[ i ] = j;
                j += 2;
            }
        }
        cout << "YES" << endl;
        for( int i = 1; i <= 2 * n; i++ )
            cout << ans[ i ] << " ";
        cout << endl;
    }

}