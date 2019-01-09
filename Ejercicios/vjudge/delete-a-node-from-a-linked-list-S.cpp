#include <iostream>

Node* Delete(Node *head, int position)
{
    
    Node *previous = NULL, *actual = head;
    int i = 0;
    
    if(position == 0)
        return head = head->next;
    
    for(i = 0; i < position; i++){
        previous = actual;
        actual = actual->next;
    }
    previous->next = actual->next;
    
    return head;
}