#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli power(lli a, lli b, lli m){
    lli n = 1;
    while(b > 0){
        if( (b & 1) == 1)
            n = (a * n) % m;
        b >>= 1;
        a = ( ( a % m ) * ( a % m ) ) % m;
    }
    return n;
}

int main(){
    lli B, P, M;
    while(cin >> B >> P >> M){
        cout << power(B, P, M) << endl;
    }
    return 0;
}