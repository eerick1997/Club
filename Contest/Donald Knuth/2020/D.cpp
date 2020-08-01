#include <bits/stdc++.h>
 
using namespace std;
using lli = long long int;
 
const lli MOD = 1e9 + 7;


lli multMod(lli a, lli b, lli n){
    lli ans = 0;
    a %= n, b %= n;
    if(llabs(b) > llabs(a)) swap(a, b);
    if(b < 0){
        a *= -1, b *= -1;
    }
    while(b){
        if(b & 1) ans = (ans + a) % n;
        b >>= 1;
        a = (a + a) % n;
    }
    return ans;
}

lli modularInverse(lli a, lli m){
    lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
    while(r1){
        si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
        ri = r0 % r1, r0 = r1, r1 = ri;
    }
    if(r0 < 0) s0 *= -1;
    if(s0 < 0) s0 += m;
    return s0;
}

lli gauss (lli n) {
    return (multMod(n, n + 1, MOD) % MOD);
}
 
lli cuadratic_serie(lli n) {
    return (multMod(multMod(n, n + 1, MOD), 2 * n + 1, MOD) * modularInverse(3, MOD)) % MOD;
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    lli n, ans, root, substract, serie_result;
    n = ans = root = substract = serie_result = 0;

    cin >> n;

    root = round(sqrtl(n));
    substract = multMod(llabs(gauss(root) - n), root, MOD);
    serie_result = cuadratic_serie(root);
    ans = serie_result - substract;

    cout << (ans % MOD) << endl;
 
    return 0;
}