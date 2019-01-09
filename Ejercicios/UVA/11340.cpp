#include <iostream>

using namespace std;

int main(){

	int N, K, M, vcharacter;
	int values[256];
	string str = "";
	float tot = 0.0; 
	//N = número de pruebas
	cin>>N;
		//recabamos dato por prueba
	for(int i = 0; i < N; i++){
		tot = 0.0;
			//Número de caracteres
		for(int i = 0; i < 256; i++){
			values[i] = 0.0;
		}
		cin>>K;
		for(int j = 0; j < K; j++){
			cin>>c>>vcharacter;
			cin.ignore();
			values[(int)(c)] = vcharacter;
		}//Fin lectura caracteres y valores

		//Cuantas líneas se van a leer
		cin>>M;
		cin.ignore();
		//Recorremos línea a línea
		for(int i = 0; i < M; i++){
			getline(cin, str);
			//Recorremos caracter a caracter la línea;
			for(int j = 0; j < str.size(); j++){
				tot += values[(int)(str[j])];
			}
		}
		printf("%0.2f$\n", tot/100);
	}
	return 0;
}
