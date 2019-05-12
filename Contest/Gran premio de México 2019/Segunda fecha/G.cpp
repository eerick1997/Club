#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){

    int n;
    cin>>n;

    vector<ll>pesos(n);
    for(int i = 0; i < n; i++){
        cin>>pesos[i];
    }

    for(int i = 0; i < n; i++){
        ///cout<<pesos[i]<<"\n";
        long double aux = ((double)pesos[i] / 5.0);
        //cout<<fixed<<setprecision(4)<<aux<<endl;
        if(aux - (ll)aux == 0){
            pesos[i] = aux; //cout<<"Entra\n";
        }else if(pesos[i] > 5){
            //cout<<"Entra 2\n";
            ll a = ll(aux);
            ll b = 1;
            //cout<<a<<" "<<b<<"\n"; 
            pesos[i] = a+b;
        }
    }

    int q;
    cin>>q;
    int x;
    for(int i = 0; i < q; i++){
        cin>>x;
        cout<<pesos[x-1]<<"\n";
    }


    return 0;
}