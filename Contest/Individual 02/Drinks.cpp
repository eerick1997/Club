#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    double n, ans;
    cin >> n;
    for(int i = 0, p; i < n; i++){
        cin >> p;
        ans += p;
    }

    cout << std::setprecision(8) << ( (ans / n) ) << std::fixed << endl;
    return 0;
}