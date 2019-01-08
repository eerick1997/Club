#include <iostream>

/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
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