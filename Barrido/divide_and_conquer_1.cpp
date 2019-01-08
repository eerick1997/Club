#include <bits/stdc++.h>
/********************************************************
 * CASOS RAROS: Que solo nos ingresen números negativos.*
 * ******************************************************/
using namespace std;

typedef long long int lli;

int main(){

    lli n, ans = 0, sum = 0, another_ans = -10e10;
    vector<lli> v;
    cin>>n;
    while(n--){
        lli a;
        cin>>a;
        v.push_back(a);
    }

    sum = 0;
    //Iteramos en todo el vector
    for(int i = 0; i < v.size(); i++){
        //El algoritmo de kadane nos dice que almenos habrá un número positivo, por tanto la mejor respuesta es cero
        //Además el valor de la suma se determina sumando la variable sum más el valor actual del vector,
        //si este valor es mayor que cero (positivo) entonces nuestro candidato a mejor respuesta ahora es
        //la suma entre la variable suma y el vector alctual, en caso contrario ya no hay mejor candidato
        //a suma contigua de valores más que cero, por tanto reiniciamos la variable 0.
        sum = ( (sum + v[i]) > 0 )? sum + v[i] : 0;
        //La respuesta siempre es el máximo, por tanto buscamos el máximo entre la suma actual y la respuesta anterior
        ans = max(sum, ans);
        another_ans = max(another_ans, v[i]);
    }
    //Kadane solo funciona si hay números positivos, si hay negativos, la respuesta será el menos negativo
    //Si el algoritmo no encontró un positivo entonces ans tendrá como resultado cero.
    if(ans == 0)
        ans = another_ans;
    cout<<ans<<endl;
}