#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *next;
    int value;
    Node(){
        next = NULL;
    }
};


Node *RemoveDuplicates( Node *head ){
    unordered_set<int> duplicates;
    Node *current = head;
    Node *previous = NULL;
    while(current -> next != NULL){

        if( duplicates.find( current -> value ) != duplicates.end() ){
            previous -> next = current -> next;
        } else {
            duplicates.insert( current -> value );
            previous = current;
        }
        current = current -> next;
    }

    return head;
}

void printList( Node *head ){
    Node *aux = head;
    cout << endl;
    while( aux -> next != NULL ){
        cout << aux -> value << " ";
        aux = aux -> next;
    }
    cout << endl;
}

int main(){
    int n, v;
    Node *head = new Node();
    Node *aux = head;

    cin >> n; 
    while(n--){
        cin >> aux -> value;
        aux -> next = new Node();
        aux = aux -> next;
    }

    printList( head );

    aux = RemoveDuplicates( head );

    printList( aux );
    
    return 0;
}