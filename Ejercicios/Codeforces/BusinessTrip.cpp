#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, ans = 0;
    vector< int > a( 12 );
    cin >> k;
    for( int i = 0; i < 12; i++ ){
        cin >> a[ i ];
    }

    sort( a.begin(), a.end() );

    for( int i = 11 ; i >= 0 && k > 0; i--, ans++ ){
        k -= a[ i ];
    }
    
    cout << ( ( ans == 12 && k > 0 ) ? -1 : ans) << endl;
    return 0;
}