#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const lli MOD = 986444689;
const lli LIM = 200005;

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
    lli a = fact[k] * fact[n - k];
    lli ans = 0;
    if(a > 0)
        ans = fact[n] * modularInverse( (a) , MOD );
    return ans % MOD;   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    lli x, T, N, K;
    pair<bool, int> e;
    factorial( LIM );
    cin >> T;
    while(T--){
        vector< int > days(200005, 3);
        string s;
        cin >> N >> K;

        cin.ignore();
        getline(cin, s);
        stringstream ss(s);

        while(ss >> x) 
            days[x - 1] = 1;
        

        getline(cin, s);
        stringstream sss(s);

        while(sss >> x){
            days[x - 1] = 2;
        }

        for(auto a : days) {
            if(a != 3)
                K -= ( (a == true) ? 2 : 1);
        }

        cout << (combination(N  + K - 1, N - 1)) << "\n";
    }
    return 0;
}
