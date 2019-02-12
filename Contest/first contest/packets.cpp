#include<bits/stdc++.h>

/***
    Mínimos paquetes se pueden formar
    Podemos obtener el número de de bits
    con eso podemos calcular todas las combinaciones que nos sirven
    log(n) + 1
**/
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << (int)(log2(n)) + 1;
    return 0;
}