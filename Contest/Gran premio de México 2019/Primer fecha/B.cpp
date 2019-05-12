#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const lli MOD = 986444689;
const lli LIM = 9999999;

vector<lli> fact(LIM);

//log2(n);
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
    return s0;
}

//n
inline void factorial(lli n){
    fact[0] = 1;
    for(lli i = 1; i <= n + 1; i++) {
        fact[i] = ( (fact[i - 1] % MOD) * (i % MOD) ) % MOD;
    }
}

//log2(n) + log2(n);
inline lli combination(lli n, lli k){
    lli ans = fact[n] * modularInverse( (fact[k] * fact[n - k]) , MOD );
    return ans % MOD;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    lli x, T, N, K;
    factorial( LIM );
    cin >> T;
    while(T--){
        string s;
        cin >> N >> K;
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);
        unordered_map<lli, bool> days;

        while(ss >> x) 
            days[x] = false;

        getline(cin, s);
        stringstream sss(s);
        while(sss >> x)
            days[x] = true;

        for(auto a : days)
            K -= ( (a.second) ? 2 : 1);

        cout << (combination(N  + K - 1, N - 1)) << "\n";
    }
    return 0;
}
