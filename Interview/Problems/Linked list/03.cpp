#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *next;
    int value;

    Node(int _value){
        value = _value;
        next = NULL;
    }
};

Node *ReverseLinkedList(Node *head){
    Node *previous = NULL;
    Node *current = head;
    Node *next = current -> next;
    while( next != NULL ){

        current -> next = previous;
        previous = current;
        current = next;
        next = current -> next;

    }
    current -> next = previous;
    return current;
}

int main(){

    int n, v;
    Node *head, *aux;
    cin >> n;

    cin >> v;
    head = new Node(v);
    aux = head;
    n--;
    while(n--){
        cin >> v;
        aux -> next = new Node(v);
        aux = aux -> next;
    } 
    cin >> n;

    //Reverse a linked list
    aux = ReverseLinkedList( head );

    for(int i = 0; i < n; i++){
        aux = aux -> next;
    }

    cout << aux -> value << endl;

    return 0;
}