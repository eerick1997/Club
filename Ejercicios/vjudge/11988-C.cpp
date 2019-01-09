#include <iostream>

using namespace std;

template<class T> struct List{

	//Estructura de un nodo
	struct Node{
		T data;
		Node *next;

		//Constructor lo invocamos cuando usamos new
		Node(T val){
			data = val;
			next = NULL;
		}
	};


	//new nos devuelve la posicion de lo que se ha definido
	//Las listas tienen una cabeza y una cola
	Node *head;
	Node *tail;
	int size;

	//Constuctor de la lista
	List(){
		tail = head = NULL;
		size = 0;
	}


	//Se añade un elemento al final de la lista
	void push_back(T val){
		Node *node = new Node(val);
		if(size == 0)
			tail = head = node;
		else{
			tail->next = node;
			tail = node;
		}
		size++;
	}

	//Elimina el último elemento de la lista
	void pop_back(){
		if(size == 0)
			throw runtime_error("Cannot erase from empty list");
		else if(size == 1){
			//Estado original
			head = tail = NULL;
		} else {
			//Vamos a recorrer la lista
			Node *previous = head;
			Node *last = head->next;
			//while(last != NULL && last->next)
			while(last && last->next){
				previous = previous->next;
				last = last->next;
			}
			//Hacemos que previous apunte a nulo
			previous->next = NULL;
			tail = previous;
			size--;
		}
	}

	//Verifica si un elemento existe
	bool exists(T val){
		if(size == 0)
			return false;
		Node * current = head;
		//while(current != null)
		while(current){
			if(current->data == val)
				return true;
			current = current->next;
		}
		return false;
	}

};	

int main(){

	List<char> *result = new List<char>(), *aux = new List<char>();

	string str;
	while(getline(cin,str)){
		bool begin = false;

		for(int i = 0; i < str.size(); i++){

			if(str[i] == '[' || str[i] == ']'){

				if(str[i] == '[')
					begin = true;
				else 
					begin = false;

				//Si ambas listas no son nulas
				if(aux->head){
					//La lista aux (izquierda) en la posición siguiente de tail será igual al 
					//head de la cola result (derecha)
					if(result->head){
						aux->tail->next = result->head;
						//La cola de la lista aux ahora debe apuntar a la cola de la lista resultante
						aux->tail = result->tail;
					}
					//La lista resultante será igual a la auxiliar
					result = aux;
					//Limpiamos nuestra lista
					aux = new List<char>;
				}
			
			} else {

				//El último caracter "importante" fue [
				if(begin){
					aux->push_back(str[i]);
				} else { //El último caracter importante fue ]
					result->push_back(str[i]);
				}
			}

		}
        // [s[
		//Quizá aux quedó con información almacenada
		if(aux->head){
			aux->tail->next = result->head;
			aux->tail = result->tail;
			result = aux;
		}
		//cout<<">>";
		while(result->head){
			cout<<result->head->data;
			result->head = result->head->next;
		}
		cout<<endl;
		result = new List<char>();
		aux = new List<char>();
	}
	return 0;
}