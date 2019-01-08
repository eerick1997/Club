#include <iostream>

using namespace std;

template <class T> struct Stack{

	struct Node{
		T data;
		Node *next;

		//Constructor
		Node(T value){
			data = vale;
			next = NULL;
		}	
	};

	Node *head;
	int size;

	Stack(){
		head = NULL;
		size = 0;
	}

	void push(T value){
		Node *node = new Node(value);

		if(size == 0)
			head = node;
		else {
			node->next = head;
			head = node;
		}
		size++;
	}

	T top(){
		if(size == 0)
			throw runtime_error("Stack is empty");
		return head->data;
	}

	void pop(){
		if(size == 0)
			throw runtime_error("You can't erase from an empty Stack");
		else {
			head = head->next;
			size--;
		}
	}

	bool isEmpty(){
		return (size == 0);
	}
	
};