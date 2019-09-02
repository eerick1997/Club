#include <bits/stdc++.h>

using namespace std;

using number = unsigned long long;

int how_many_bits(number x) {
    int bits = 0;
    while( x != 0 ){
        if( x & 1 == 1 )
            bits++;
        x >>= 1;
    }
    return bits;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    number n, k;
    cin >> n >> k;

    number min_with_k = 0;
    for (int i = 0; i < k; ++i) {
        min_with_k <<= 1;
        min_with_k++;
    }

    auto current = max(n, min_with_k);
    while (how_many_bits(current) != k or current <= n) ++current;
    
    cout << current << endl;
    return 0; 
}