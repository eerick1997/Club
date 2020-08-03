#include <bits/stdc++.h>
 
using namespace std;
using lli = long long int;
 
const lli MOD = 1000000007;

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
    return (n % MOD * (n + 1) % MOD) % MOD;
}
 
lli cuadratic_serie(lli n) {
    int A = (2 * n + 1) % MOD;
    return (((gauss(n) * A) % MOD) * modularInverse(3, MOD)) % MOD;
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    lli n, ans, root, substract, serie_result;
    n = ans = root = substract = serie_result = 0;

    cin >> n;
    
    root = round(sqrtl(n));
    
    
    substract = (((gauss(root) - (n % MOD)) % MOD) * (root % MOD)) % MOD;
    serie_result = cuadratic_serie(root) % MOD;
    ans = (serie_result - substract) + MOD;

    cout << (ans % MOD) << endl;
 
    return 0;
}