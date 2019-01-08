#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
vector< lli > cuentas;

lli Hippie(C n_cuentas){
    lli ans, current, i = 0 j = 0;
    for(int i = 0, j = 0; i < (cuentas.size()/2) && i < cuentas.size(); i++){
        current = cuentas[i]
        
    }
    return ans;
}

void duplicate(vector< lli >& cuenta){
    for(int i = 0; i < cuenta.size(); i++){
        cuentas.push_back(cuenta[i]);
    }
}

void accumulate(){
    for(int i = 1; i < cuentas.size(); i++){
        cuentas[i] += cuentas[i - 1];
    }
}

int main(){
    lli C, N;
    vector< lli > cuenta;
    cin >> C >> N;
    while(N--){
        lli a;
        cin >> a;
        cuenta.push_back(a);
        cuentas.push_back(a);
    }
    duplicate(cuenta);
    accumulate();
    Hippie(C);
    return 0;
}