#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bool isPrime(lli a){
    for(int i = 2; i <= sqrt(a); i++)
        if(a % i == 0) return false;
    return true;
}

int main(){
    lli n;
    cin >> n;
    if(isPrime(n))
        cout << 1 << endl;
    else if(n % 2 == 0)
        cout << 2 << endl;
    else {
        cout << ((isPrime(n - 2) ? 2 : 3)) << endl;
    }
    return 0;
}