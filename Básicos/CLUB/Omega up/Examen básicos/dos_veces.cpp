#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isCharacter(char character);

using namespace std;
int main(){
	char nombre[30], linea[1024], linea2[1024];
	FILE* file;
	cin>>nombre;
	file = fopen(nombre, "r");
	if(file){
		while(fgets(linea, 1024, (FILE*)file)){
			strcpy(linea2, linea);
			for(int i = 0; linea[i]; i++)
				if(isCharacter(linea[i]))
					linea[i] = toupper(linea[i]);
				cout<<linea<<"\n";

			for(int i = 0; linea[i]; i++)
				if(isCharacter(linea[i]))
					linea2[i]=(char)tolower(linea2[i]);
				cout<<linea2<<"\n";
		}
		fclose(file);
	}	
}

int isCharacter(char character){
	int value = 0;
	if((character >= 65 && character <= 90) || (character >= 97 && character <= 122) || character == ' ' && character != '\n')
		value = 1;
	return value;
}