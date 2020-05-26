

#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *next;
    node( int ndata ){
        data = ndata;
        next = nullptr;
    }
};



node *reverse_iterative( node *head ){
    node *curr_node = head;
    node *prev_node = nullptr;
    node *next_node = head -> next;

    while( curr_node != nullptr ) {
        next_node = curr_node -> next;
        curr_node -> next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    return prev_node;
}


node *reverse_recursive( node *head ) {
    if( head == nullptr or head -> next == nullptr)
        return head;

    node* reversed = reverse_recursive( head -> next );
    head -> next -> next = head;
    head -> next = nullptr;
    return reversed;
}

void print( node* head ) {
    cout << endl;
    node *current = head;
    while( current != nullptr ) {
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
}

int main() {
    node *head = nullptr;
    node *tail = nullptr;
    node *new_head = nullptr;
    head = new node( 1 );
    tail = head;
    tail -> next = new node( 2 );
    tail = tail -> next;
    tail -> next = new node( 3 );
    tail = tail -> next;
    tail -> next = new node( 4 );
    tail = tail -> next;
    print( head );
    new_head = reverse_recursive( head );
    print( new_head );
}