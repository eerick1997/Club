/**APLICACIÓN SUMA DE ACUMULADOS

Problema: Se quiere conocer el área máxima de la cual se puede adquirir un departamento con cierta cantidad
de dinero.

Restricciones: 1<= T <= 100
			   1<=N,M <= 100
			   1<= D <= 10^9
			   P_ij <= 10^6

Para realizar el cálculo del área podemos realizar un barrido o suma de acomulados en 2D, con eso
podemos obtener un área conociendo solamente el valor anterior que se tiene o bien el valor d ela casilla
con esto reducimos el tiempo que tardaríamos en calcular el área de la matriz que se nos dará como entrada

El recorrido lo podemos hacer de la siguiente manera

	for(int i = 0; i < N; i ++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k <= N; k++){
				for(int l = 0; l <= M; l++)
			}
		}
	}

	Pero el hacer esto lleva mucho tiempo de procesamiento además de que la complejidad es muy álta
	concretamente N^2 * M^2

	1) Acumulados
	2) Checar todas las alturas
	a) Hacer el barrido
**/

#include <iostream>
const int MAXN = 109;
using namespace std;
typedef long long Long;
Long acum[MAXN][MAXN];

//Acumulados
Long Query(int iniI, int finI, int iniJ, int finJ){
	return acum[finI][finJ] - acum[iniI-1][finJ]
	- acum[finI][iniJ-1] + acum[iniI-1][iniJ-1];
}

void printMat(int N, int M){
	for(int i = 1; i <= N; i++){
			cout<<endl;
		for(int j = 1; j <= M; j++)
			cout<<" "<<acum[i][j];
	}
	cout<<endl;
}

int main(){
	int T, N, M, D, caso = 1;
	cin>>T;
	while(T--){
		cin>>N>>M>>D;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				cin>>acum[i][j];
			}
		}
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				acum[i][j] += acum[i][j-1];
			}
			for(int j = 1; j <= M; j++)		
				acum[i][j] += acum[i-1][j];
		}

		Long area = 0, minCosto = ((Long)1)<<60;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j <= N; j++){

				Long tmpArea = 0, costo = 0;
				for(int k = 1, l = 1; l <= M; l++){
					costo += Query(i,j,l,l);
					while(k <= l && costo>D)
						costo -= Query(i, j, k,k),k++;

					tmpArea = (j-i+1)*(l-k+1);

					if(tmpArea > area || (tmpArea == area && costo < minCosto))
						area = tmpArea, minCosto = costo;
				}
			}
		}
		cout<<"Case #"<<caso++<<": " <<area<<" "<<minCosto<<"\n";
	}
}