#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    lli N, S, accum, coins = 0;
    cin >> N >> S;
    for(int i = N; i > 0; i--){
        coins += S / i;
        S = S % i;
        if(S == 0){
            cout << coins << "\n";
            break;
        }
    }
}  