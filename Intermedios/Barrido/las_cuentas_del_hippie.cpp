#include <bits/stdc++.h>

using namespace std;

int main(){

    int C, N, a, respuesta = INT_MAX;
    cin >> C >> N;
    vector<int> pulsera(2*N);
    for(int i = 0; i < N; i++){
        cin >> a;
        pulsera[i] = a;
        pulsera[N + i] = a;
    }
    
    int cuentas = 0;
    for(int i = 0, j = 0; i < 2*N; i++){
        while(j < C && j <){
            if(pulsera[j++])
                cuentas++;
        }

        if(cuentas == C)
            respuesta = max(respuesta, C - );
    }

    cout << respuesta << endl;

    return 0;
}