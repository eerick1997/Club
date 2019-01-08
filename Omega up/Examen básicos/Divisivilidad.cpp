/** Divisibilidad

Debemos de tomar varias consideraciones primero que N debe estar entre 1 y 18
además de que P debe estar entre 2 a 100 y también todos los factores deben
de estar entre 0 y P-1 además de que el algoritmo debe funcionar aún que los primeros
números sean ceros.

Aritmética modular
(a+b)%m = (a%m+b%m)%m

a == b % m
es lo mismo que
a%m = b%m por ejemplo sea a = 11 y b = 21 y m = 10
11%10 == 21%10
1 = 1;

c(a==b) % m;
ca = cb % m;

a == b % m
c == d % m
ac == bd % m


**/

/**#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int N, P;
	cin>>N>>P;
	for(int i = N-1; i >= 0; i--)
		cout<<(fmod(pow(10,i), P))<<" ";
	return 0;
}**/


//Versión 2.0 RECOMENDADO

#include <iostream>
#include <math.h>

using namespace std;

int N, P, a[18+5];

int main(){	
	cin>>N>>P;
	long long pot = 1;
	for(int i = 0; i < N; i++){
		a[i] = pot%P;
		pot *= 10;
	}
	for(int i = N-1; i>0; i--)
		cout<<a[i]<<" ";
	cout<<a[0]<<"";
	return 0;
}
