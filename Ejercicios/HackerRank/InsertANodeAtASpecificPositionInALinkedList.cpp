#include <bits/stdc++.h>

using namespace std;

struct Node {
    int32_t data;
    Node *next;
    Node( int32_t data ){ this -> data = data; next = nullptr; }
};

struct LinkedList {

    LinkedList() { head = tail = nullptr; }

    Node *head, *tail;

    void insert( int32_t data ) {
        Node *node = new Node( data );
        if( head == nullptr )
            head = node;
        else
            tail -> next = node;
        tail = node;
    }

    void print( ){
        Node *aux = head;
        cout << endl;
        while( aux != nullptr ) {
            cout << aux -> data << " ";
            aux = aux -> next;
        }
        cout << endl;
    }
};

Node* insertNodeAtPosition(Node* head, int32_t data, int32_t position) {

    Node *aux = head;
    Node *node = new Node( data );
    if( head == nullptr )
        return NULL;

    for( int32_t i = 0; i < position - 1; i++ )
        aux = aux -> next;

    node -> next = aux -> next;
    aux -> next = node;

    return head;
}

int32_t main() {
    LinkedList *linkedList = new LinkedList();
    int32_t size, data, position;

    cin >> size;

    for( int32_t i = 0, number; i < size; i++ ) {
        cin >> number;
        linkedList -> insert( number );
    }

    cin >> data >> position;

    insertNodeAtPosition( linkedList -> head, data, position );
    linkedList -> print();
}