bool has_cycle(Node *head) {
    Node *slow, *fast;
    
    if( head == NULL )
        return false;

    slow = fast = head;

    while( slow and fast and fast -> next ){

        slow = slow -> next;
        fast = fast -> next -> next;

        if( slow == fast )
            return true;
        
    }
    return false;
}