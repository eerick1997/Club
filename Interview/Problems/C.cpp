#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli mod (lli n, lli m){
    return ( (n < 0) ? m - ( abs(n) % m ) : n % m );
}

int main(){
    int T, index = 0;
    cin >> T;
    while(T--){
        lli n, m;
        cin >> n >> m;
        vector<lli> A(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
        
        if(A[0] != -1){
            for(int i = 1; i < n; i++){
                if(A[i] == -1)
                    A[i] = ( A[i - 1] + 1 ) % m;
            }
        } else if (A[n - 1] != -1) {
            for(int i = n - 2; i >= 0; i--){
                if(A[i] == - 1)
                    A[i] = ( ( A[i + 1] - 1 ) % m + m ) % m;
            }
        } else {
            for(int i = n - 1; i >= 0; i--){
                if(A[i] != -1){
                    index = i;
                    break;
                }
            }

            for(int i = index + 1; i < n; i++){
                A[i] = ( A[i - 1] + 1 ) % m;
            }

            for(int i = n - 2; i >= 0; i--){
                A[i] = ( ( A[i + 1] - 1 ) % m + m ) % m;
            }
            
        }

        for(int i = 0; i < n; i++)  
            cout << A[i] << " ";
        cout << endl;
    }
    return 0;
}