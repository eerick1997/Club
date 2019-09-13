#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
vector< lli > numbers;

int main(){
    lli n, ans = 0;
    cin >> n;
    numbers.assign( n, 0 );
    for( int i = 0; i < n; i++ )
        cin >> numbers[ i ];

    sort(numbers.begin(), numbers.end());

    for( int i = 0; i < n / 2; i++ )
        ans += ( numbers[ i ] + numbers[ n - 1 - i ] ) * ( numbers[ i ] + numbers[ n - 1 - i ] );
    
    cout << ans << endl;
}