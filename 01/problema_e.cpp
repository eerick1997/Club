#include <iostream>

using namespace std;

int main(){
	string str;
	//Usando getline podemos leer una línea completa con todo y espacios
	while(getline(cin,str)){
		//cout<<str<<'\n';
		//Si queremos imprimir un caracter:
		//cout<<str[0]<<'\n';
		for(int i = str.size()-1; i >= 0; i--)
			cout<<str[i];
		cout<<'\n';
	}
	return 0;
}