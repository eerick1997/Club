#include <iostream>
Node* Reverse(Node* head){
Node *actual, *auxNext, *previous = NULL;
	actual = head;
	while(actual){
		auxNext = actual->next;
		actual->next = previous;
		previous = actual;
		actual = auxNext;
	}
	return previous;
}