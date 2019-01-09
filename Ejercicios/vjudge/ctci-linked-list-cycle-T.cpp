#include <iostream>

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