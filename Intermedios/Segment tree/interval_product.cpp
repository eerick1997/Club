#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100002];
int ST[300002];

//Devuelve el signo
int helper(int x){
	if(x == 0)
		return 0;
	else if(x < 0)
		return -1;
	else
		return 1;
}

//Actualiza el segment tree
/**
	@param: nodo => nodo actual
	@param: ini => rango inicial de búsqueda
	@param: fin => rango final de busqueda
	@param: x => nodo que vamos ha actualizar
	@param val => nuevo valor
**/
void update(int nodo, int ini, int fin, int x, int val){
	if(ini == fin && ini == x)
		ST[nodo] = val;
	else if(ini <= x && x <= fin){
		int mitad = (ini + fin)/2;
		update(nodo * 2, ini, mitad, x, val);
		update(nodo *2+1, mitad+1, fin, x, val);
		ST[nodo] = ST[nodo * 2] * ST[nodo * 2 + 1];
	}
}
//Pedimos información al ST
/**
	@param: nodo => nodo actual
	@param: ini => inicio de la busqueda
	@param: fin => fun de la busqueda
	@param: l => rango izquierdo de la query
	@param: r => rango derecho de la query

	@return valor del rango
**/
int query(int nodo, int ini, int fin, int l, int r){
	if(fin < l || r < ini){
		return 1;
	} else if(l <= ini && fin <= r){
		return ST[nodo];
	} else {
		int mitad = (ini + fin)/2;
		int izq = query(nodo * 2, ini, mitad, l, r);
		int der = query(nodo * 2 + 1, mitad + 1, fin, l ,r);
		return (izq * der);
	}
}
void inicializaST(int nodo, int ini, int fin){
	if(ini == fin){
		ST[nodo] = helper(arr[ini]);
	} else {

		int mitad = (ini + fin) /2;
		inicializaST(nodo * 2, ini, mitad);
		inicializaST(nodo * 2 + 1, mitad + 1, fin);
		ST[nodo] = ST[nodo * 2] * ST[nodo * 2 + 1];
	}
}


int main(){

	while(cin>>n>>k){
		for(int i = 1; i <= n; i++){
			cin>> arr[i];
		}

		inicializaST(1,1,n);

		for(int  i = 1; i <= k; i++){
			char opcion;
			cin>>opcion;
			if(opcion == 'C'){
				int x, val;
				cin>>x>>val;
				update(1, 1, n, x, helper(val));
			} else {
				int l, r;
				cin>>l>>r;
				int res = query(1,1,n,l,r);
				if(res == 0){
					cout<<"0";
				} else if(res < 0){
					cout<<"-";
				} else {
					cout<<"+";
				}
			}
		}
		cout<<"\n";
	}

	return 0;
}