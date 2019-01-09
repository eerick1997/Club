#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Hay entre 1 y 100 estudiantes vestidos de manera grotesca
/**Debemos encontrar la velocidad mínima a la que debe correr el payaso
Sin que sea atrapado**/
/**	Entrada
   	Primer línea contiene un entero menor o igual a 50, con el número de casos de prueba
   	A continuación se leen T casos. Cada línea del caso es un entero separado por espacios
   	el primer entero N es es el número de estudiantes vestidos de manera grotesca el resto
   	de la línea tiene N enteros cada uno representa la velocidad de la criatura en metros
   	por segundo 1 <= c_i <= 10,000

   	Salida:
   	Una línea **/
	int main(){
	vector<int> v;
	int T, N, X;
	string str;
	cin>>T;
	//T casos
	for(int i = 1; i <= T; i++){

		//Leemos una cadena donde el primer dígito es el número de estudiantes
		cin>>N;
		if(N == 1){
			cin>>X;
			cout<<"Case "<<i<<": "<<X<<endl;
		} else {
			for(int j = 0; j < N; j++) {
				cin>>X;
				v.push_back(X);
			}
			sort(v.begin(), v.end());
			cout<<"Case "<<i<<": "<<v[v.size()-1]<<endl;
		}
		v.clear();
	}
	return 0;
}