#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli bin_mul(lli a, lli b){
    lli n = 0;
    a %= n;
    b %= n;
    if(abs(b) > abs(a))
        swap(a, b);
    if(b < 0){
        a *= -1
        b *= -1;
    }
    while(b){
        if(b & 1)
            ans = (ans + a) % n;
        b >>= 1;
        a = (a + a) % n;
    }
    return n;
}

int main(){

    String l1, l2;
    lli acum = 0;
    cin >> l1 >> l2;
    for(int i = 0; i < l1.size(); i++){

    }
    return 0;
}