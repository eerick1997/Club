/**
 * Tema: Combinaciones
 *          Considerar -> 
 *              (n + k - 1, n - 1)
 * 
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli modularInverse(lli a, lli m){
    lli r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
    while(r1){
        si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
        ri = r0 % r1, r0 = r1, r1 = ri;
    }
    if(r0 < 0)
        s0 *= -1;
    if(s0 < 0)
        s0 += m;
    return s0;
}

int main(){

    lli x, T, N, K;
    string s;

    cin >> T >> N >> K;

    cin.ignore();
    getline(cin, s);
    stringstream ss(s);
    vector<lli> nSupervisor, nBoss;

    while(ss >> x) 
        nSupervisor.push_back( x );

    getline(cin, s);
    stringstream sss(s);
    while(sss >> x)
        nBoss.push_back( x );

    return 0;
}
