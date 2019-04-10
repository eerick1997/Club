#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    lli t, a, b, k;
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        cout << ( ((k + 1) >> 1) - ( k >> 1 ) ) << endl;
    }
    return 0;
}