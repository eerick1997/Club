#include <bits/stdc++.h>
using namespace std;

bool sieve[1000];

void fillSieve(){
    
    for(int i = 4; i <= 1000; i += 2)
        sieve[i] = true;
    
    for(int i = 3; i <= 1000; i += 2){
        if(!sieve[i])
            for(int j = i*i; j < 1000; j += i){
                sieve[j] = true;
            }
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int M, sum;
    string Mi;
    fillSieve();
    cin >> M;
    while(M--){
        Mi = "";
        cin >> Mi;
        for(int i = sum = 0; i < Mi.size(); i++)
            sum += Mi[i] - '0';
        if(sieve[sum])
            cout << "No ";
        cout << "UltraPrimo\n";
    }
    return 0;
}