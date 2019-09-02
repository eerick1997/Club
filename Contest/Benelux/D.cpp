#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli modularInverse( lli a, lli m ){
    lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
    while( r1 ){
        si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
        ri = r0 % r1, r0 = r1, r1 = ri;
    }
    if( r0 < )
}

int main(){

    return 0;
}