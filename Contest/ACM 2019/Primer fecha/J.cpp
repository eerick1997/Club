#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
const lli MOD = 1000000007;

lli power(lli b, lli e){
    lli ans = 1;
    while(e){
        if(e & 1){
            ans = ( (ans % MOD) * (b % MOD) ) % MOD;
        }
        e >>= 1;
        b = ((b % MOD) * (b % MOD)) % MOD;
    }
    return ans % MOD;
}

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
    return s0 % MOD;
}

lli multMod(lli a, lli b, lli n){
    lli ans = 0;
    a %= n, b %= n;
    if( abs(b) > abs(a) )
        swap(a, b);
    if(b < 0)
        a *= -1, b*= -1;
    
    while(b){
        if(b & 1)
            ans = (ans + a) % n;
        b >>= 1;
        a = (a + a) % n;
    }
    return ans % MOD;
}

lli ans(lli p, lli q, lli m, lli n){
    lli a = 2 * ( (n % MOD) + (m % MOD) ) % MOD;
    lli b = (power(p, q + 1) - 1) % MOD;
    lli c =  modularInverse( (p - 1) , MOD) % MOD;
    return  multMod( multMod(a, b, MOD), c, MOD ) % MOD;
}

int main(){
    lli T, M, N, P, Q;
    cin >> T;
    while(T--){
        cin >> M >> N;
        cin >> P >> Q;
        cout << ans(P, Q, M, N) << endl;
    }
    return 0;
}