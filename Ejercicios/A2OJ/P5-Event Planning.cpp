#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	vector<int> v;
	int N, B, H, W, p = 0, a = 0;
	bool isAnOption = true;

	while(cin>>N>>B>>H>>W && N != 0 && B != 0 && H != 0 && W != 0){

		v.clear();
		//Recabamos los datos por hotel
		for(int i = 0; i < H; i++){

			isAnOption = true;
			//Obtenemos el precio por persona por cada fin de semana
			cin>>p;

			//Obtenemos habitaciones disponibles que habrá para cada fin de semana
			for(int j = 0; j < W; j++){
				//Obtenemos las habitaciones disponoibles
				cin>>a;
				//Deben ser suficientes para todas los N participantes

				if(/** (a - N) < 0 ||**/ a == 0 ){ //Si las habitaciones son menos que los participantes
					//No es una opción por tanto saltamos al siguiente hotel
					isAnOption = false;
				} 
			}//Habitaciones

			//Debemos saber si el presupuesto es suficiente (participants * price)
			if((B - (N*p)) < 0){
				isAnOption = false;
			}

			//Finalmente si es una opción almacenamos el valor de este hotel
			if(isAnOption == true){
				v.push_back(N*p);
			}
		}//Hoteles

		//verificamos el tamaño del vector
		if(v.size() > 0){//Debe tener almenos un elemento
			//Como hay elementos ordenamos el contenido del vector de menor a mayor
			sort(v.begin(), v.end());
			//Tomamos el valor más pequeño (opción más económica)
			cout<<v[0]<<endl;
		} else {
			cout<<"stay home"<<endl;
		}
	}//No se han detectado más lecturas

	return 0;
}