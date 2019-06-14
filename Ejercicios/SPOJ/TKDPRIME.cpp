#include <bits/stdc++.h>
#define LIM 100000002
using namespace std;
typedef long long int lli;

vector<lli> primes;
vector<bool> isPrime;

void primesSieve(){
    lli n = LIM;
    isPrime.resize(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    primes.push_back(2);
    for(lli i = 4; i <= n; i += 2) isPrime[i] = false;
        lli limit = sqrt(n);

    for(lli i = 3; i <= n; i += 2){
        if(isPrime[i]){
        primes.push_back(i);
        if(i <= limit)
            for(int j = i * i; j <= n; j += 2 * i)
                isPrime[j] = false;
        }
    }
}

int main(){
    int Q, I;

    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    primesSieve();

    cin >> Q;
    while(Q--){
        cin >> I;
        cout << primes[I - 1] << endl;
    }
    return 0;
}