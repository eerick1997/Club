#include <bits/stdc++.h>
#define FALSE 1
#define TRUE 2
#define NONE 0

using namespace std;
typedef long long int lli;
const lli MOD = 986444689;
const lli LIM = 200001;

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
    for(lli i = 1; i < n; i++) 
        fact[i] = ( (fact[i - 1] % MOD) * (i % MOD) ) % MOD;
}

//log2(n) + log2(n);
inline lli combination(lli n, lli k){
    lli a = 0, ans = 0;
    if( (n - k) >= 0){
        a = fact[k] * fact[n - k];
        ans = fact[n] * modularInverse( (a) , MOD );
    }
    return ans % MOD;   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    lli x, T, N, K;
    string s;
    factorial( LIM );
    cin >> T;
    while(T--){
        vector< short > days(LIM / 2, NONE);
        cin >> N >> K;

        cin.ignore();
        getline(cin, s);
        stringstream ss(s);

        while(ss >> x) 
            days[x - 1] = FALSE;
        

        getline(cin, s);
        stringstream sss(s);

        while(sss >> x)
            days[x - 1] = TRUE;
        
        for(int i = 0; i < days.size(); i++)
            K -= days[i];

        cout << (combination(N + K - 1, N - 1)) << "\n";
    }
    return 0;
}
