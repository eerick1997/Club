//Available at: https://www.hackerrank.com/challenges/reverse-a-linked-list/problem
#include <bits/stdc++.h>

using namespace std;

struct Singly_Linked_List {
    struct Node {
        int val;
        Node *next;
        Node( int nval) {
            val = nval;
            next = nullptr;
        }
    };

    Node *head, *tail;
    int size;
    Singly_Linked_List() {
        head = tail = nullptr;
        size = 0;
    }

    void insert( int val ) {
        Node *new_node = new Node( val );
        if( size == 0 )
            head = tail = new_node;
        else {
            tail -> next = new_node;
            tail = new_node;
        }
        size++;
    }

    //This is the unique function that you need to code
    //Just consider that it receive a parameter and returns something
    void reverse() {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while( curr != nullptr ) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        tail = head;
        head = prev;
        
    }

    void print() {
        Node *curr = head;
        cout << endl;
        while( curr != nullptr ){
            cout << curr -> val << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio( false );
    cout.tie( nullptr );
    cin.tie( nullptr );

    int test_cases;
    int numbers;
    int value;
    cin >> test_cases;
    while( test_cases-- ) {
        Singly_Linked_List *linked_list = new Singly_Linked_List();
        cin >> numbers;
        while( numbers-- ) {
            cin >> value;
            linked_list -> insert( value );
        }
        linked_list -> reverse();
        linked_list -> print();
    }
}