/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    
    int i = 0;
    
    if(!head)
        return false;
    
    while(head){
        head = head->next;
        i++;
        if(i > 100)
            return true;
    }
    return false;
}
