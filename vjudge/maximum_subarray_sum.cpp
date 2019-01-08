/**
	12/06/2018
**/

#include<iostream>
#include<algorithm>
int arr[10<<9];
using namespace std;

	int MaxSubCruzado(int p, int q, int r){
		int maxDer = -10<<9, maxIzq = -10<<9;
		int aux = q+1, suma = 0;
		while(p >= q){
			suma+=arr[q];
			q--;
			maxIzq = max(maxIzq, suma);
		}
		suma = 0;
		while(aux <= r){
			suma += arr[aux];
			aux++;
			maxDer = max(maxDer, suma);
		}
		return maxIzq + maxDer;
	}

	//Calculamos el máximo elemento de un subarreglo
	int MaxSubArr(int p, int q){
		if(p == q)
			return arr[p];
		int mid = (p + q)/2;
		return max({MaxSubArr(p,mid), MaxSubArr(mid+1, q), MaxSubCruzado(p, mid, q)});
	}



	int main(){
		cin.tie(0);
		//Desincrinizamos la entrada estándar
		ios::sync_with_stdio(0);
		int T, N;
		cin>>T;
		while(T--){
			cin>>N;
			for(int q = 0; q < N; q++){
				cin>>arr[q];
			}
		}
		int res = MaxSubArr(0, N-1);
		sort(arr, arr+N);
		int sub = arr[N-1];
		for(int i = N-2; i>= 0 && arr[i] > 0; i--){
			sub += arr[i];
		}
		cout<<res<<" "<<sub<<"\n";
	}