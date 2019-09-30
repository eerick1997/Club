#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );
    lli l, r, ans;
    string ls, rs, anss;
    
    cin >> l >> r;

    bool invalid;

    for( int i = l; i <= r; i++ ){
        invalid = false;
        anss = to_string( i );
        vector< int > bucket( 10, 0 );

        for( char c : anss )
            bucket[ c - '0' ]++;
        
        for( int e : bucket ){
            if( e > 1 )
                invalid = true;
        }

        if( !invalid ){
            cout << anss << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}