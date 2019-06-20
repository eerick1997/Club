#include <bits/stdc++.h>

using namespace std;

struct Node{

    Node *next;
    int value;

    Node( int _value ){
        value = _value;
        next = NULL;
    }

};

typedef struct LinkedList{
    
    Node *tail;
    Node *head;
    int size;

    LinkedList(){
        tail = head = NULL;
        size = 0;
    }

    void insertAtTail(int value){
        Node *node = new Node( value );
        if( size > 0 ){
            tail -> next = node;
            tail = node;
        } else {
            tail = head = node;
        }
        size++;
    }

    void insertAtHead(int value){
        Node *node = new Node( value );
        if( size > 0 ){ 
            node -> next = head;
            head = node;
        } else {
            head = tail = node;
        }
        size++;
    }

    void Delete(int i){
        if( i < size && i >= 0 ){
            Node *aux = head;
            //If we want to delete the first element
            if( i == 0 )
                head = head -> next;
            //If we want to delete the last element
            else if ( i == size ){

                for( int j = 0; j <= size - 1; j++ )
                    aux = aux -> next;

                aux -> next = NULL;
                tail = aux;
    
            } else {
                for( int j = 0; j < i - 1; j++)
                    aux = aux -> next;
                aux -> next = aux -> next -> next;
            } 
            size--;
        }
    }

    void DeleteAtHead(){
        if( size == 1)
            head = tail = head -> next; 
        else
            head = head -> next;
        size--;
    }

    int Search(int i){

        if( i < size ){
            Node *aux = head;
            for(int j = 0; j < i; j++)
                aux = aux -> next;
            return aux -> value;
        }

        return INT_MIN;
    }

    bool isEmpty(){
        return ( size == 0 );
    }

    int getSize(){
        return size;
    }

    void print(){
        Node *aux = head;
        while( aux != NULL ){
            cout << aux -> value << "\t";
            aux = aux -> next;
        }
        cout << endl;
    }
} LinkedList;

int main(){

    LinkedList *linkedList = new LinkedList();
    linkedList -> insertAtTail( 0 );
    linkedList -> insertAtTail( 1 );
    linkedList -> insertAtTail( 2 );
    linkedList -> insertAtTail( 3 );
    
    linkedList -> print();

    linkedList -> insertAtHead( 4 );
    linkedList -> insertAtHead( 5 );
    linkedList -> insertAtHead( 6 );
    linkedList -> insertAtHead( 7 );
    
    linkedList -> print();

    linkedList -> DeleteAtHead();
    linkedList -> DeleteAtHead();
    linkedList -> DeleteAtHead();
    linkedList -> DeleteAtHead();

    linkedList -> print();

    linkedList -> insertAtHead( 4 );
    linkedList -> insertAtHead( 5 );
    linkedList -> insertAtHead( 6 );
    linkedList -> insertAtHead( 7 );
    
    linkedList -> print();

    linkedList -> Delete( linkedList -> getSize() - 1 );
    linkedList -> print();
    linkedList -> Delete( linkedList -> getSize() - 1 );
    linkedList -> print();
    linkedList -> Delete( linkedList -> getSize() - 1 );
    linkedList -> print();
    linkedList -> Delete( linkedList -> getSize() - 1 );
    linkedList -> print();

    cout << linkedList -> getSize() << endl;

    for(int i = 0; i < linkedList -> getSize(); i++)
        cout << linkedList -> Search(i) << " \t ";
}