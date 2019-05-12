#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
const lli MOD = 1000000007;

inline lli power(lli b, lli e){
    lli ans = 1;
    b %= MOD;
    while(e){
        if(e & 1)
            ans = (ans * b) % MOD;

        e >>= 1;
        b = (b*b) % MOD;
    }
    return ans;
}

inline lli modularInverse(lli a, lli m){
    lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
    while(r1){
        si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
        ri = r0 % r1, r0 = r1, r1 = ri;
    }
    if(r0 < 0) 
        s0 *= -1;
    if(s0 < 0)
        s0 += m;
    return s0 % MOD;
}

inline lli multMod(lli a, lli b, lli n){
    lli ans = 0;
    a %= n, b %= n;
    if( abs(b) > abs(a) )
        swap(a, b);
    if(b < 0)
        a = -1, b = -1;
    
    while(b){
        if(b & 1)
            ans = (ans + a) % n;
        b >>= 1;
        a = (a + a) % n;
    }
    return ans;
}

int main(){
    lli T, m, n, p, q;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> m >> n >> p >> q;
        lli a = 2 * ( (n % MOD) + (m % MOD) ) % MOD;
        lli b = (power(p, q + 1) - 1);
        lli c =  modularInverse( (p - 1) , MOD) % MOD;

        cout << (multMod( multMod(a, b, MOD), c, MOD ) % MOD) << "\n";
    }
    return 0;
}