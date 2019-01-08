/**Listas**/
//Librerias
#include <iostream>

using namespace std;

//Estructura de una lista
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

 
	Node* Reverse(Node* head){

		Node *actual, *auxNext, *previous = NULL;

		//El primer valor a manipular será el inicio de la lista
		actual = head;

		//Mientras el valor actual != NULL
		while(actual){
			//El valor siguiente será el que tenga el valor actual->siguiente
			auxNext = actual->next;
			//El siguiente del nodo actual será igual al anterior
			actual->next = previous;
			//El valor anterior será igual al valor actual
			previous = actual;
			//El valor actual será igual al siguiente
			actual = auxNext;

		}
		return prev;
	}

};

//Probamos nuestra lista
int main(){

	List<int> *list = new List<int>();

	list->push_back(1);
	list->push_back(2);
	list->push_back(3);

	list->Reverse();

	if(list->exists(1))
		cout<<":)"<<endl;

	cout<<"head: "<<list->head->data<<" tail: "<<list->tail->data<<endl;
	cout<<list->size<<endl;
	list->pop_back();
	if(!list->exists(1))
		cout<<":("<<endl;
	cout<<"head: "<<list->head->data<<" tail: "<<list->tail->data<<endl;
	cout<<list->size<<endl;
	return 0;
}