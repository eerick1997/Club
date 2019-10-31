#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int q, n;
    cin >> q;
    while( q-- ){
        int ans = 0;
        cin >> n;
        vector< int > V( n );
        
        for( int i = 0; i < n; i++ )
            cin >> V[ i ];
        bool flag1 = false, flag2 = false;

        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                if( abs( V[ i ] - V[ j ] ) == 1 && !flag1 ){
                    flag1 = true;
                }
            }
        }

        cout << ( flag1 ? 2 : 1 ) << endl;
    }
    return 0;
}