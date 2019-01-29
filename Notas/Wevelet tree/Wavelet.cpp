#include <bits/stdc++.h>
using namespace std;
/*
	Las queries son indexadas en base 1.
	La complejidad de cada query es de: O(log(max_element)).
	El arbol se construe desde [from,to) con valores no negativos en el rango [x,y]
*/
struct WaveletTree
{
	int lo, hi;//lo: el minimo valor en nuestra subsecuencia y hi: el mayor valor.
	WaveletTree *left, *right;//Apuntadores a nuestros hijos izquierdo y derecho.
	vector<int> mapLeft;//Vector que contendra todos los mapLeft que necesitemos
	/*
		from: iterador que apunta hacia el inicio de la subsecuencia
		to: iterador que apunta hacia el fin de la subsecuencia
		lo: valor minimo
		hi: valor maximo
	*/
	WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int lo, int hi)/*:lo(x),hi(y)*/{
		this->lo=lo;
		this->hi=hi;
		if(from >= to) 
			return;
		//	Calculamos nuestro m, valor que ayudara a dividir la subsecuencia
		int m = (lo + hi) >> 1;
		//Esta funcion nos indica si el parametro x es menor o igual a nuestra m previamente calculada
		auto f = [m](int x){
			return x <= m;
		};

		//	Reservamos la cantidad(numero de elementos en el rango) necesaria para nuestro arreglo de mapLeft.
		mapLeft.reserve(to - from + 1);
		//	Como indexamos en 1, anadimos un cero para obviar el mapLeft[0]=0.
		mapLeft.push_back(0);
		

		for(auto it = from; it != to; ++it){
			/*
				*it: El valor de la posicion en la que esta el iterador
				Al llamar a la funcion f() con el parametro *it, esta nos devolvera un 1 si el parametro
				es menor o igual a nuestra m, y un 0 si no lo es.
			*/
			auto leq = f(*it);//leq: Less than or equal
			//	Al valor de leq que obtengamos le anadiremos el ultimo valor agregado a nuestro mapLeft. 
			//	Iremos acumulando los valores.
			mapLeft.push_back(mapLeft.back() + leq);
		}
		/*
			Si hi!=lo esto significa que nuestra subsecuencia tiene dos o mas valores distintos.
			Por lo tanto, debemos crear a nuestros nodos hijos ya que todavia no llegamos a un nodo hoja.
		*/
		if(hi != lo){
			/*
				A la funcion stable_partition le mandamos como parametros
				from: el iterador al inicio de nuestra subsecuencia
				to: el iterador al fin de nuestra subsecuencia
				f: una funcion de comparacion que necesita para dividir los elementos de manera adecuada

				La funcion dividira la subsecuencia en dos partes, sin alterar el orden en el que aparecen los numeros. 
				Los elementos menores o iguales a nuestro m se iran a nuestro hijo izquierdo y los demas al derecho.
				stable_partition regresa un iterador al primer elemento de la segunda parte.
				
				Informacion: https://en.cppreference.com/w/cpp/algorithm/stable_partition

				pivot:iterador al primer elemento de los elementos mayores a m
			*/
			auto pivot = stable_partition(from, to, f);
			//	Creamos a nuestro hijo izquierdo con los valores hasta pivot(menores o iguales a m)
			//	y definimos a m como su hi
			left = new WaveletTree(from, pivot, lo, m);
			//	Creamos a nuestro hijo derecho con los valores despues del pivot
			//	y definimos a m+1 como su lo
			right = new WaveletTree(pivot, to, m + 1, hi);
		}
	}
	/*
		NOTA IMPORTANTE
		En esta implementacion no es necesario calcular el mapRight para cada indice de cada subsecuencia.
		Si ya tenemos el mapLeft, podemos saber que mapRight = index - mapLeft(S,index).
		Por lo que la cantidad de elementos en el rango [l,r] que iran a la derecha sera igual a:
		(r-rb) - (l-lb)
	*/

	/*
		Encontrar el k-esimo elemento en ese rango si los numeros estuvieran ordenados.

		Cuando llamen a esta funcion en su main, asegurense que el k no rebase el numero de elementos en el rango.
		Si la llaman sin validar eso, les regresara un valor erroneo.
	*/
	int kth(int l, int r, int k){
		//	Si estamos en un rango que no es valido
		if(l > r) 
			return -1;
		//	Si llegamos a un nodo hoja entonces nuestro resultado es el valor en ese nodo
		if(lo == hi) 
			return lo;
		int lb = mapLeft[l - 1], rb = mapLeft[r];
		//	inLeft es la cantidad de elementos en el rango [l,r] que iran a la izquierda
		//	Esto se calcula mediante la resta: mapLeft[r] - mapLeft[l-1]
		int inLeft = rb - lb;
		//	Si nuestra cantidad de numeros en inLeft es mayor o igual a nuestra k, iremos a la izquierda
		//	y nuestros indices ahora seran mapLeft[l-1]+1 y mapLeft[r]
		if(k <= inLeft) 
			return left->kth(lb + 1, rb, k);
		else // Si es k es mayor a inLeft, iremos a la derecha. Hay que restar inLeft al k.
			return right->kth(l - lb, r - rb, k - inLeft);
	}

	//number of elements less than or equal to x in [l, r]
	/*
		En esta funcion buscaremos el numero de elementos menores o iguales a x en [l,r].
		Tendremos tres casos en esta funcion:
		1.- Cuando x es menor a cualquier elemento en la subsecuencia, es decir: x < lo.
		2.- Cuando x es mayor que algunos elementos en la subsecuencia, es decir: lo <= x < hi.
		3.- Cuando x es mayor a TODOS los elementos en la subsecuencia, es decir: hi <= x.

		En el caso numero 1 podemos ver que no hay ningun traslape, no tomaremos a algun elemento de la subsecuencia
		ya que todos son mayores a nosotros. Retornaremos el valor de 0.

		Para el caso 3 tenemos un traslape TOTAL, por lo que anadiremos a todos los elementos en la subsecuencia
		a nuestro resultado. La cantidad de elementos se calcula como r - l + 1.

		Por ultimo, en el caso 2 tenemos un traslape parcial, por lo que tendremos que usar una tecnica parecida a 
		cuando usamos un segment tree. Lo que haremos es una llamada recursiva para calcular la cantidad de elementos
		que son menores o iguales a x en nuestros hijos izquierdo y derecho. Como no sabemos si nuestra x es mayor,menor
		o igual que nuestra m; entonces buscaremos en nuestros dos hijos hasta que regrese algun valor valido.
	*/
	int lessThanOrEqual(int l, int r, int x){
		//Caso 1
		if(l > r || x < lo) 
			return 0;
		//Caso 3
		if(hi <= x) 
			return r - l + 1;
		//Usamos el mapLeft de nuevo para obtener nuestros indices
		int lb = mapLeft[l - 1], rb = mapLeft[r];
		//Caso 2
		return left->lessThanOrEqual(lb + 1, rb, x) + right->lessThanOrEqual(l - lb, r - rb, x);
	}
};

int main(){
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i){
		cin >> num[i];
	}
	//Pare entender como funciona el end() de un vector: http://www.cplusplus.com/reference/vector/vector/end/
	WaveletTree w(num.begin(), num.end(),*min_element(num.begin(), num.end()),*max_element(num.begin(), num.end()));
	return 0;
}