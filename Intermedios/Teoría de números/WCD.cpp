#include <bits/stdc++.h>
#define 210e9 MAX 

using namespace std;

typedef long long int lli;

lli GCD(lli a, lli b){
    return (b == 0) ? GCD(b, a % b) : a;
}

vector<bool> buildSieve(lli n){
    lli root = sqrt(n);
    vector<bool> sieve(n + 2, true);
    for(lli i = 4; i < n; i += 2)
        sieve[i] = false;

    for(lli i = 3; i <= root; i++){
        if(sieve[i])
            for(lli j = i*i; j <= n; j += i)
                if(sieve[j])
                    sieve[j] = false;
    }
    return sieve;   
}

int main(){
    lli n;
    vector<bool> sieve = buildSieve(MAX);
    cin >> n;
    while(n--){
        lli a, lli b;
        cin >> a >> b;

        
    }
}