/**Cubote.cpp**/
/** Se nos brindan los valores de las caras de un cubo pequeño
debemos de construir un cubo más grande con estos cubitos de nxnxn
Pero la usma total de todas las caras visibles debe ser mínima.

Dividimos el cubo en secciones las aristas(se ven dos caras) 
y también tenemos los vértices, de los cuales se les ven 3 caras

¿Cómo encontramos los vértices?
Basándonos en un dibujo siempre valdrá 4

¿Cuantas aristas hay?
Si vemos las caras de frente notemos que es 4(N-1)
Pero si el cubo lo vemos por arriba es 4(N-2)

¿Como obtenemos el número de caras?
Solo son visibles 5 caras por tanto esto es a 5n^2
Para calcular las caras que nos restarán del cubo al total restemos
el número de aristas menos los vértices
Concluimos que #caras = 5n^2 - 2#Aristas - 3#vertices
De las aristas se multiplica por dos porque sabemos que las aristas muestran dos caras
De los vértices se multiplica por tres porque sabemos que los vértices muestran tres caras

Para comparar las caras debemos obtener el peso de la cara cara minima de A,B,C,D,E,F

wAristaMin=min(A,B,C,D,E,F)
wAristaMin=min{(A,B),(A,C),(A,D),(A,E),(B,D),(B,E),(B,F),(C,D),(C,E),(C,F),(D,F),(E,F)}
mVérticeMin={(E,D,A),(A,B,D),(E,A,C),(A,C,B),(B,D,F),(C,B,F),(E,C,F),(E,D,F)}
**/

#include <iostream>

using namespace std;

//Declaramos nuestras variables
long long int n;
long long int a,b,c,d,e,f;

int main(){

	cin>>n;
	cin>>a>>b>>c>>d>>e>>f;

	//Este número es muy pequeño jamás será el mayor
	long long int mayor = -1;
	mayor = max(mayor, a);
	mayor = max(mayor, b);
	mayor = max(mayor, c);
	mayor = max(mayor, d);
	mayor = max(mayor, e);
	mayor = max(mayor, f);

	if(n==1){
		cout<<(a+b+c+d+e+f) - mayor;
	} else {
		long long int vertices = 4;
		long long int aristas = 4*(n-1)+4*(n-2);
		long long int caras = 5*n*n - aristas * 2 - vertices * 3;
		long long int wCaraMin = 100;//Este valor es muuuy grande jamás será el menor
		wCaraMin = min(wCaraMin, a);
		wCaraMin = min(wCaraMin, b);
		wCaraMin = min(wCaraMin, c);
		wCaraMin = min(wCaraMin, d);
		wCaraMin = min(wCaraMin, e);
		wCaraMin = min(wCaraMin, f);

		long long int wArisMin = 150;
		wArisMin = min(wArisMin, a + b);
		wArisMin = min(wArisMin, a + c);
		wArisMin = min(wArisMin, a + d);
		wArisMin = min(wArisMin, a + e);
		wArisMin = min(wArisMin, b + d);
		wArisMin = min(wArisMin, b + f);
		wArisMin = min(wArisMin, b + c);

		wArisMin = min(wArisMin, c + b);
		wArisMin = min(wArisMin, c + e);
		wArisMin = min(wArisMin, c + f);
		wArisMin = min(wArisMin, d + f);
		wArisMin = min(wArisMin, e + f);

		long long int wVerticeMin = 151;
		wVerticeMin = min(wVerticeMin, e + d + a);
		wVerticeMin = min(wVerticeMin, a + b + d);
		wVerticeMin = min(wVerticeMin, e + a + c);
		wVerticeMin = min(wVerticeMin, a + c + b);
		wVerticeMin = min(wVerticeMin, b + d + f);
		wVerticeMin = min(wVerticeMin, c + b + f);
		wVerticeMin = min(wVerticeMin, e + c + f);
		wVerticeMin = min(wVerticeMin, e + d + f);
		//Finalmente calculamos el total que es
		long long int res = caras * wCaraMin + vertices * wVerticeMin + aristas*wArisMin;
		cout<<res<<"\n";

	}
	return 0;
}