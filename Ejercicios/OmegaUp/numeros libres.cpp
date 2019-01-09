#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int GCD(lli a, lli b){
    return (b == 0) ? a : GCD(b, a%b);
}

int main(){

    lli a, b, N;
    cin >> N;
    while(N--){
        cin >> a >> b;
        cout << ( (GCD(a, b) == 1)? "SI" : "NO") << endl;
    }
    return 0;
}