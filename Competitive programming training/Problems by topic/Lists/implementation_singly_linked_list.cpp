#include <bits/stdc++.h>

using namespace std;

struct Singly_Linked_List {
    struct Node {
        int value;
        Node *next;

        Node( int n_value ){
            value = n_value;
            next = nullptr;
        }
    };

    Node *head, *tail;
    int size;
    
    Singly_Linked_List(){
        head = tail = nullptr;
        size = 0;
    }

    void insert_at_head( int value ){
        Node *new_node = new Node( value );
        if( size == 0 )
            head = tail = new_node;
        else {
            new_node -> next = head;
            head = new_node;
        }
        size++;
    }

    void insert_at_tail( int value ){
        Node *new_node = new Node( value );
        if( size == 0 )
            head = tail = new_node;
        else {
            tail -> next = new_node;
            tail = tail -> next;
        }
        size++;
    }

    void remove( int index ) {
        Node *current = head;

        if( index < 0 and index >= size )
            return;

        if( size == 0 )
            return;

        if( size == 1 )
            head = tail = nullptr;

        if( index == 0 )
            head = head -> next;
        
        for( int i = 1; i < index; i++ )
            current = current -> next;

        
        if( size - 1 == index ){
            tail = current;
            tail -> next = nullptr;
        } else
            current -> next = current -> next -> next;

        size--;
    }

    void print() {
        Node *current = head;
        cout << endl;
        while( current != nullptr ) {
            cout << current -> value << " ";
            current = current -> next;
        }
        cout << endl;
    }
};

int main() {
    Singly_Linked_List *linked_list = new Singly_Linked_List();
    //Insert 5 elements
    linked_list -> insert_at_tail( 1 );
    linked_list -> insert_at_tail( 2 );
    linked_list -> insert_at_tail( 3 );
    linked_list -> insert_at_tail( 4 );
    linked_list -> insert_at_tail( 5 );

    linked_list -> print();

    linked_list -> insert_at_head( 1 );
    linked_list -> insert_at_head( 2 );
    linked_list -> insert_at_head( 3 );
    linked_list -> insert_at_head( 4 );
    linked_list -> insert_at_head( 5 );

    linked_list -> print();

    linked_list -> remove( 9 );

    linked_list -> print();

}