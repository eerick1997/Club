#include <bits/stdc++.h>

using namespace std;
using lli = unsigned long long int;

const lli MOD = 1e9 + 7;

int main() {
    lli n, ans = 0;
    cin >> n;
    for(int k = 1; k <= n; k++)
        ans = (ans % MOD + (lli)round(sqrt(k)) % MOD) % MOD;

    cout << ans << endl;
    return 0;
}