#include <bits/stdc++.h>

using namespace std;

struct Node{
    int value;
    Node *next;

    Node( int _value ){
        value = _value;
        next = NULL;
    }
};

struct Queue{

    Node *back;
    Node *front;
    int size;

    Queue(){
        back = front = NULL;
        size = 0;
    }

    void Enqueue( int value ){
        Node *node = new Node( value );
        if( size == 0 )
            back = front = node;
        else {
            node -> next = back;
            back = node;
        }

        size++;
    }

    void Dequeue(){
        Node *aux = back;
        if( size > 1 ){
            
            while( aux -> next != NULL )
                aux = aux -> next;

            aux -> next = NULL;
            front = aux;

        } else if( size == 1 )
            front = back = NULL;
        else 
            return;
        size--;
    }

    bool IsEmpty(){
        return (size == 0);
    }

    int Top(){
        return (front -> value);
    }

    int GetSize(){
        return size;
    }
    
    void print(){
        cout << endl;
        Node *aux = back;
        while( aux != NULL ){
            cout << aux -> value << " ";
            aux = aux -> next;
        }
        cout << endl;
    }
};

int main(){

    Queue *queue = new Queue();
    queue -> Enqueue(0);
    cout << "\nTop: " << queue -> Top() << endl;
    queue -> Enqueue(1);
    cout << "\nTop: " << queue -> Top() << endl;
    queue -> Enqueue(2);
    cout << "\nTop: " << queue -> Top() << endl;
    queue -> Enqueue(3);
    cout << "\nTop: " << queue -> Top() << endl;
    queue -> print();
    queue -> Dequeue();
    cout << "\nTop: " << queue -> Top() << endl;
    queue -> Dequeue();
    cout << "\nTop: " << queue -> Top() << endl;
    queue -> Dequeue();
    cout << "\nTop: " << queue -> Top() << endl;
    queue -> Dequeue();
    cout << "\nTop: " << queue -> Top() << endl;
    cout << "\nIsEmpty? " << queue -> IsEmpty() << endl;
    cout << "\nSize " << queue -> GetSize() << endl;
    queue -> Enqueue(3);
    queue -> print();
    queue -> Enqueue(2);
    queue -> print();
    queue -> Enqueue(1);
    queue -> print();
    queue -> Enqueue(0);
    queue -> print();
    cout << "\nTop " << queue -> Top() << endl;

    return 0;
}