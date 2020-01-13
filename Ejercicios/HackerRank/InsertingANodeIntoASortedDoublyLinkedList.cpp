#include <bits/stdc++.h>

using namespace std;

struct Node {
    int32_t data;
    Node *next, *prev;
    Node( int32_t data ){
        this -> data = data;
        next = prev = nullptr;
    }
};

struct DoubleLinkedList {
    Node *head, *tail;

    DoubleLinkedList() { head = tail = nullptr; }

    void insert( int32_t data ) {

        Node *node = new Node( data );

        if( head == nullptr )
            head = node;
        else {
            tail -> next = node;
            node -> prev = tail;
        }
        tail = node;
    }

    void printLtoR() {
        Node *node = head;
        cout << endl;
        while( node != nullptr ) {
            cout << node -> data << " ";
            node = node -> next;
        }
        cout << endl;
    }

    void printRtoL() {
        Node *node = tail;
        cout << endl;
        while( node != nullptr ) {
            cout << node -> data << " ";
            node = node -> prev;
        }
        cout << endl;
    }
};

Node* sortedInsert( Node* head, int32_t data ) {
    Node *node = new Node( data );
    Node *aux = head;
    while( aux != nullptr ) {
        if( aux -> data >= data ) {
            if( aux -> prev != nullptr  && aux -> next != nullptr ){
                node -> next = aux;
                node -> prev = aux -> prev;
                aux -> prev -> next = node;
                aux -> prev = node;
                return head;
            } else if( aux -> prev == nullptr ) {
                node -> next = aux;
                aux -> prev = node;
                return node;
            } else if( aux -> next == nullptr ) {
                node -> prev = aux -> prev;
                aux -> next = node;
                return head;
            }
            break;
        }
        aux = aux -> next;
    }
    return head;
}

int32_t main() {

    int32_t test_cases, size, data;
    cin >> test_cases;
    while( test_cases-- ) {
        DoubleLinkedList *doubleLinkedList = new DoubleLinkedList();
        cin >> size;
        for( int32_t i = 0, number; i < size; i++ ){
            cin >> number;
            doubleLinkedList -> insert( number );
        }
        cin >> data;

        Node *aux = sortedInsert( doubleLinkedList -> head, data );
        cout << endl;
        while( aux != nullptr ) {
            cout << aux -> data << " ";
            aux = aux -> next;
        }
        cout << endl;
    }
    return 0;
}