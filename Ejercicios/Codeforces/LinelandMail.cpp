#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    int n;
    cin >> n;
    vector< lli > X( n + 2 );
    X[ 0 ] = INT64_MIN;
    for( int i = 1; i <= n; i++ )
        cin >> X[ i ];
    X[ n + 1 ] = INT64_MIN;
    
    for( int i = 1; i <= n; i++){
        
        lli MAX = max( (lli)abs( X[ i ] - X[ 1 ] ), (lli)abs( X[ i ] - X[ n ] ) );
        lli MIN = min( (lli)abs( X[ i ] - X[ i + 1 ] ), (lli)abs( X[ i ] - X[ i - 1 ] ) );
        cout << MIN << " " << MAX << endl;
    }
    return 0;
}