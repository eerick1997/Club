#include <bits/stdc++.h>
#define INF 2000000;

using namespace std;

int arr[1000002];
int derCercano[1000002];
int ST[2100002];

int m, q;

void preproceso(){
	map<int, int> mapa;

	for(int i = m; i>= 1; i--){
		//Existe
		if(mapa[arr[i]] > 0){
			derCercano[i] = mapa[arr[i]];
			mapa[arr[i]] = i;
		} else {
			derCercano[i] = INF;
			mapa[arr[i]] = i;
		}
	}

}

void inicializaST(int nodo, int ini, int fin){
	if(ini == fin){
		ST[nodo] = derCercano[ini];
	} else {
		int mitad = (ini + fin) /2;
		inicializaST(nodo * 2, ini, mitad);
		inicializaST(nodo * 2 + 1, mitad + 1, fin);
		ST[nodo] = min(ST[nodo * 2], ST[nodo * 2 +1]);
	}
}

int query(int nodo, int ini, int fin, int l, int r){
	if(fin < l || r < ini){
		return INF;
	} else if(l <= ini && fin <= r){
		return ST[nodo];
	} else {
		int mitad= (ini + fin)/2;
		int izq =query(nodo * 2, ini, mitad, l,r);
		int der = query(nodo * 2 + 1, mitad + 1, fin, l, r);
		return min(izq, der);
	}
}

int main(){
	while(cin>>m>>q && m != 0 && q != 0){
		for(int i = 1; i <= m; i++){
			cin>>arr[i];
		}
		preproceso();
		inicializaST(1, 1, m);
		for(int i = 1; i <= q; i++){
			int l, r;
			cin>>l>>r;
			int idx = query(1,1,m,l,r);
			if(idx > r){
				cout<<"OK"<<endl;
			} else{
				cout<<arr[idx]<<endl;
			}
		}
		cout<<endl;
		

	}	
	return 0;
}