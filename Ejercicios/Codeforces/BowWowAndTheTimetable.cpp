#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli ans = -1;
    bool flag = false;
    string s;
    cin >> s;

    for( int i = s.size() - 1; i >= 0; i-- ){
        if( ( (i + 1) & 1) )
            ans++;

        if( s[ i ] == '1' && i != 0 )
            flag = true;
    }

    if( !(s.size() & 1) && !flag ) 
        ans++;
    cout << ( flag ? ans + 1 : ans ) << endl;
}