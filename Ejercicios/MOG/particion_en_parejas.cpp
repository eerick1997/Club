#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    lli k, ans = 0;
    cin >> k;
    vector<int> personas(2*k);
    for(int i = 0; i < 2*k; i++)
        cin >> personas[i];

    sort(personas.begin(), personas.end());

    for(int i = 0; i < k; i++)
        ans += (abs(personas[i] - personas[2*k - i - 1]));
    cout << ans << endl;
    return 0;
}