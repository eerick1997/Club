#include <bits/stdc++.h>
using namespace std;
int main (){


    int n, t;
    cin>>n>>t;
    int aux = t;
    vector<int>num(n);
    for(int i = 0; i < n; i++){
        cin>>num[i];
    }

    sort(num.begin(), num.end());

    int cont = 0;

    for(int i = 0; i < n; i++){
        if( t - num[i] > 0){
            cont++;
            t-=num[i];
        }
    }

    int cont2 = 0;
    aux-=num[num.size()-1];
    cont2++;
    for(int i = num.size()-2; i >= 0; i--){
        if( aux - num[i] > 0){
            cont2++;
            aux-=num[i];
        }
    }

    cout<<cont2<<" "<<cont<<endl;




    return 0;
}