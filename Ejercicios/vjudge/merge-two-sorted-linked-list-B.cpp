/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node *auxA = headA, *auxB = headB, *result = NULL, *prevA = NULL, *prevB = NULL;
    Node *tail = NULL;
    
    if(headB == NULL)
        return headA;
    else if(headA == NULL)
        return headB;
    //int i = 0;
    //Mientras auxA != NULL && auxB != NULL
    while(auxA && auxB){   
        if(auxA->data <= auxB->data){
            prevA = auxA;
            prevA->next = auxA->next;
            if(result == NULL){
                tail = result = auxA;
            } else {
                tail->next = auxA;
                tail = auxA;
            }
            auxA = auxA->next;
        } else {
            prevB = auxB;
            prevB->next = auxB->next;
            if(result == NULL){
                tail = result = auxB;
             } else {
                tail->next = auxB;
                tail = auxB;
            }
            auxB = auxB->next;                
        }
    }//while
    
    if(auxA && auxB == NULL){
        tail->next = auxA;
        tail = auxA;
    } else if(auxB && auxA == NULL){
        tail->next = auxB;
        tail = auxB;
    }
    
    return result;
}