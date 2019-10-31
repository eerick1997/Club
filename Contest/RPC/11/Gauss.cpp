#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli n;
    cin >> n;
    for( lli i = 1; i <= (n + 0); i++ )
        cout << i << " " << ( ( i * (i + 1) ) / 2 ) << endl;
    
    return 0;
}