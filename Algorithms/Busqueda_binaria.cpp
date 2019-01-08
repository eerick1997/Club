/**Búsqueda binaria

4 paradígmas
	-> Búsqueda completa (fuerza bruta)
	-> Greedy (Algoritmos borazes "Que me conviene en este momento")
	-> Programación dinámica (Dynamic Programming 'DP')
	-> Paradigma de divide y vencerás

	La búsqueda binaria es un pedazo muy pequeño de divide y venceras. También se le llama a
	la búsqueda binaria como (simplificación / Bisección)
	Supongamos que queremos saber la capacidad de un barril entonces utilizamos 
	[a,b] si procesamos
	[0, 1,000]: 500 -
	[0, 500): 250 -
	(0, 250): 125 +
	(125, 250): 187.5 -
	(125, 187.5): 156.25 +
	(156.25, 187.5): 171.875 -
	(156.25, 171.875): 164.0625 -
	.
	.
	.
	(158.965, 158.995): 158.980 correcto

	siendo así se puede modelar 
	f <-> x < y -> f(x) <= f(y) ó
			x < y -> f(x) >= f(y)
			La función tiene un órden

**/
#include <iostream>

using namespace std;

int main(){
	
	return 0;
}