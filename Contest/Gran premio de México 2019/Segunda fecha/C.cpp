#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
const lli MOD = 1000000007;

lli modularInverse(lli a, lli m){
    lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
    while(r1){
        si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
        ri = r0 % r1, r0 = r1, r1 = ri;
    }
    if(r0 < 0)
        s0 *= -1;
    if(s0 < 0)
        s0 += m;
    return s0;
}

lli powerMod(lli b, lli e, lli m){
    lli ans = 1;
    b %= m;
    if(e < 0){
        b = modularInverse(b, m);
        e *= -1;
    }
    while(e){
        if(e & 1)
            ans = (ans * b) % m;
        e >>= 1;
        b = (b * b) % m;
    }
    return ans;
}

int main(){
    lli T, N, ans = 0;
    cin >> T;
    while(T--){
        cin >> N;
        ans = (10 * powerMod(9, N - 1, MOD)) % MOD;
        cout << ans << endl;
    }
    return 0;
}