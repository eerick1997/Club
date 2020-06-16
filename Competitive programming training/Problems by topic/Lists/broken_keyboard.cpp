#include <bits/stdc++.h>
const bool LEFT = true;
const bool RIGHT = false;

using namespace std;

struct Node {
    char val;
    Node *next;
    Node( char nval ) {
        val = nval;
        next = nullptr;
    }
};

struct Linked_List {
    Node *head, *tail;
    Linked_List() {
        head = tail = nullptr;
    }

    void insert( char val ) {
        Node *new_node = new Node( val );
        if( head == nullptr )
            head = tail = new_node;
        else {
            tail -> next = new_node;
            tail = new_node;
        }
    }

    void print( ) {
        Node *curr = head;
        while( curr != nullptr ) {
            cout << curr -> val;
            curr = curr -> next;
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    string input;
    while( cin >> input ) {
        Linked_List *left = new Linked_List();
        Linked_List *right = new Linked_List();

        bool flag = RIGHT;
        for( char c : input ) {
            
            if( c == '[' ) {
                flag = LEFT;
            } else if( c == ']' ) {
                flag = RIGHT;
                if( left -> head != nullptr ) {
                    left -> tail -> next = right -> head;
                    left -> tail = right -> tail;
                    right -> head = left -> head;
                    right -> tail = left -> tail;
                    left -> head = left -> tail = nullptr;
                }
            } else {
                if( flag == LEFT )
                    left -> insert( c );
                else 
                    right -> insert( c );
            }
        }
        
        /*if( left -> head != nullptr ) {
            left -> tail -> next = right -> head;
            left -> tail = right -> tail;
            right -> head = left -> head;
            right -> tail = left -> tail;
            left -> head = left -> tail = nullptr;
        }*/

        /*if( right -> head == nullptr )
            left -> print();
        else 
            right -> print();*/
    }

    return 0;
}