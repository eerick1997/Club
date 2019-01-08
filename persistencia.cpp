/** ESTRUCTURAS DE DATOS PERSOSTENTES
->DEF: Mantener sus antiguas versiones después de ser modificadas
**/

struct PStack{
    PStack *sig;
    int x;
    PStack() : sig(null), x(0){}

}

Pstack *version[1000];
PStack *push(int v, int x){
    PStack *nuevo = new PStack;
    nuevo -> sig = version[v];
    nuevo -> x = x;
    return nuevo;
}

PStack *pop(int v){
    return version[v] -> sig;
}

int main(){
    version[i] = push(i-1, 10);
    version[i] = pop(i-1);
}

/****************************************************************************
 *                     Que sucede en un segment tree?
 * Ejercicio 1:
 * Pensemos en el siguiente problema:
 * ->Dado un multiset originalmente vacío implementar las siguientes operaciones:
 *  >Insertar elemento x 1 <= x <= 1,000
 *  >Consultar de cuentos elementos hay mayores a A y menores a B
 * 
 * Si usamos un segment tree no persistente podemos retornar a los nodos padre
 * la cantidad de nodos hijo que cumplen la condición. 
 * 
 * ¿Pero como añadimos nodos? Tendríamos que reconstruir todo el árbol
 * 
 * Si añadimos
 * 
 * ¿Cuantos elementos mayores a A y menores, B insertamos entre la
 * i-ésima operación y la j-ésima operación?
 * 
 * Debemos crear un segment tree persistente
 * 
 * Ejercicio 2:
 * 
 * Dado un arreglo con n-elementos, responder:
 * >Entre las posiciones L y R, cuántos elementos mayores a 
 * A y menores a B existen 
 * 
 * Ejemplo:
 * 1, 4, 6, 3, 2, 3
 * 
 * Complejidad
 * O(nlog(n) + qlog(n)) -> TIEMPO
 * O(n + nlog(n))       -> MEMORIA
 * **************************************************************************/



