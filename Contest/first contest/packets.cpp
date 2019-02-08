#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli c = 0;

vector<lli> primes;
vector<lli> primeFactors;

void build_sieve(lli n){
    int root = sqrt(n);
    primes.resize(n + 1);
    for(lli i = 4; i <= n; i += 2)
        primes[i] = 2;

    for(lli i = 3; i <= root; i += 2)
        if(!primes[i])  
            for(lli j = i*i; j <= n; j+=i)
                if(!primes[j])
                    primes[j] = i;
}

void primeFactorsSieve(lli n){
    primeFactors.push_back(primes[n]);  
    while(n && primes[n]){
        primeFactors.push_back(primes[n]);
        n /= primes[n];
    }
    primeFactors.push_back(1);
}

int main(){
    lli n;
    cin >> n;
    build_sieve(n);
    primeFactorsSieve(n);
    cout << primeFactors.size()<< endl;

}