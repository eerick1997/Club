/**Uso de cadenas en C
Para usar cadenas en C usamos la siguiente síntaxis
char cadena[100]
cuando llegamos al final de cadena se encuentra el caracter nulo o fin de cadena
el cual es '\0' **/
#include <stdio.h>

int main(){
	char cadena[100];
	while(scanf("%s", cadena) != EOF){
		printf("%s\n", cadena);
	}
	return 0;
}
