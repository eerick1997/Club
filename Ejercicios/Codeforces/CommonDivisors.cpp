#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    int n;
    lli GCD, v;
    cin >> n;
    vector< lli > V( n );
    for( int i = 0; i < n; i++ )
        cin >> V[ i ];
    
    GCD = V[ 0 ];
    for( int i = 1; i < n; i++ )
        GCD = __gcd( GCD, V[ i ] );

    cout << GCD << endl;
    
    return 0;
}