/**	Operaciones de bits	**/
/**	
	Bit: La unidad mínima de medida
	Operaciones
	Corrimientos
	->izquierda
	->derecha
	and
	or
	xor
	.
	.
	.

	Supongamos que quiere encender el n-ésimo bit
	int prender(int n, int pos){ 
		return ( (n) | (1<<pos));
	}

	int apagar(int n, int pos){
		return ( (n) ^ (1 << pos))
	}
**/

#include <iostream>

using namespace std;

int prender(int n, int pos);
int apagar(int n, int pos);

int main(){
	int n, pos;
	cin>>n>>pos;
	cout<<prender(n,pos)<<endl;
	cput<<apagar(n,pos)<<endl;
	return 0;
}

int prender(int n, int pos){
	return ( (n) | (1 << pos) );
}

int apagar(int n, int pos){
	return ( (n) ^ (1 << pos) );
}