#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){

	int N, K, M, values[256], vcharacter;
	unsigned char c;
	unsigned long long total;

	//N = número de pruebas
	cin>>N;
	cin.ignore();
	//recabamos dato por prueba
	while(N--){
		//Inicializamos total con cero
		total = 0;
		//Inicializamos el valor de todos los caracteres con cero
		for(int i = 0; i < 256; i++){
			values[i] = 0;
		}
		//Número de caracteres que serán pagados
		cin>>K;
		while(K--){
			cin>>c>>vcharacter;
			cin.ignore();
			//Guardamos en la posición valor ASCII de ese caracter el valor que se introdujo
			values[(int)c] = vcharacter;
		}//Fin lectura caracteres y valores

		//Cuantas líneas se van a leer
		cin>>M;
		cin.ignore();
		//Recorremos línea a línea
		while(M--){
			while((c = cin.get()) != '\n'){
				total += values[(int)c];
			}
		}
		printf("%0.2f$\n", total/100.0);
	}
	return 0;
}