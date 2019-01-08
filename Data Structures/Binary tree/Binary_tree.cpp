/**Árbol binario de búsqueda**/
/**Es un árbol que a lo más puede tener dos hijos
Todos los elementos del lado derecho son mayores al nodo "padre"
Todos los elementos del lado izquierdo son menores o iguales al nodo padre

Operaciones
find(x) log_2(N)
insert(x) log_2(N)
erase(x) log_2(N)

Recorridos
	->in-orden
	->pos-orden
	->pre-orden**/

#include <iostream>

using namespace std;

struct root{
	root *left;
	root *right;
	T data;

	root(T value){
		left = right = NULL;
		data = value;
	}
};

void in(root){

	if(root){  
		return;
	}

	in(root->left);
	cout<<root->data;
	in(root->right);
}

void pos(root){
	if(root) return;
	pos(root->right);
	pos(root->left);
	cout<<(root->data);
}

int main(){

	return 0;
}