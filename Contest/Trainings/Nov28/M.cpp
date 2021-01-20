#include <bits/stdc++.h>

using namespace std;

vector<int> lowestPrime;
void lowestPrimeSieve(int n){
    lowestPrime.resize(n + 1, 1);
    lowestPrime[0] = lowestPrime[1] = 0;

    for(int i = 2; i <= n; ++i) 
        lowestPrime[i] = (i & 1 ? i : 2);
        
    int limit = sqrt(n);

    for(int i = 3; i <= limit; i += 2)
    if(lowestPrime[i] == i)
    for(int j = i * i; j <= n; j += 2 * i)
    if(lowestPrime[j] == j) lowestPrime[j] = i;
}

int main() {
    int n, m;
    cin >> n >> m;
    lowestPrimeSieve(m);
    cout << lowestPrime[m] << endl;
}