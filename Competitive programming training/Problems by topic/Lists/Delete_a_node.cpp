#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node *next;
    node(){ next = nullptr; }
};

node *deleteNode( node *head, int position ) {
    node *current = head;
    if( position == 0 )
        return head -> next;

    for( int i = 0; i < position - 1; i++ )
        current = current -> next;

    current -> next = current -> next -> next;

    return head;
}

void printList( node *head ){
    node *current = head;
    cout << endl;
    while( current != nullptr ) {
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int n, input, position;
    node *head, *tail, *ans;
    head = tail = nullptr;
    cin >> n;
    while( n-- ) {
        node *current = new node();
        cin >> input;
        current -> val = input;
        if( head == nullptr )
            head = tail = current;
        else 
            tail -> next = current;
        tail = current;
    }
    cin >> position;
    ans = deleteNode( head, position );
    printList( ans );
    return 0;
}