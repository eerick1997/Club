#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    lli n, ans = 0;
    vector<lli> a;
    cin >> n;
    for(int i = 0, v; i < n; i++){
        cin >> v;
        a.push_back(v);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        ans += abs(a[i] - (i + 1));
    }
    cout << ans << endl;
}