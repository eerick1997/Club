#include <iostream>
#include <queue>
using namespace std;

//canguro consume 1 unidad de comida sea grande o pequeño
int main(){
	//C comida y N el número de movimientos
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C, N, Mi;
	char c;
	cin>>C>>N;
	//Caracter a leer en las siguientes n líneas
	
	queue<int> q;
	 
	for(int i = 0; i < N; i++){
		cin>>c;
		if(c == 'N'){
			cin>>Mi;
			q.push(Mi);
		} else if(c == 'A'){
			C -= (q.front()+1);
			q.pop();
		} else if(c == 'C'){
			cout<<q.size()<<'\n';
		} else if(c == 'R'){
			cout<<C<<'\n';
		}
	}
	return 0;
}