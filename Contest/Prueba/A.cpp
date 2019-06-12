#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, n, last = -1, j = 0;
    cin >> n >> k;
    for(int i = 0, v = 0; i < n; i++){
        cin >> v;
        if( v >= k && last != v)
            j++;
        
        last = v;
    }

    cout << ( (!j) ? j : j + 1) << "\n";
    return 0;
}