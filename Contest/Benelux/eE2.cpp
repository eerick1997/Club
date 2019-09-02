#include <bits/stdc++.h>

using namespace std;

using number = unsigned long long;

int bits( number x ){
    int bits = 0;
    while( x != 0 ){
        if( (x & 1) == 1)
            bits++;
        x >>= 1;
    }
    return bits;
}

number decrease(number n, number k){
    number extra = bits( n ) - k + 1;
    number i = 1;
    number found = 0;
    while( found < extra ){
        if( n & i ) found++;
        if( found == extra ){ n += i; break; }
        
        i <<= 1;
    }
    while( i > 0 ){
        i >>= 1;
        n &= ~i;
    }
    return n;
}

number increase( number n, number k){
    number i = 1;
    number need = k - bits( n );
    while( need > 0 ){
        if( (n & i) == 0 ){
            n |= i;
            need--;
        }
        i <<= 1;
    }
    return n;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    number n, k;
    cin >> n >> k;
    n++;
    if( bits( n ) > k )
        cout << decrease( n, k ) + 1 << endl;
    else if( bits( n ) < k )
        cout << increase( n, k ) << endl;
    else 
        cout << n << endl;
}