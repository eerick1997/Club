#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    int n;
    lli MAX = -1, SUM = 0;
    cin >> n;
    for( lli i = 0, v; i < n; i++ ){
        cin >> v;
        MAX = max(MAX, v);
        SUM += v;
    }
    if( !(SUM & 1) && MAX <= (SUM - MAX) )
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}