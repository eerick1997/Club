#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node( int nval ){
        val = nval;
        next = nullptr;
    }
};

Node *merge( Node *head_1, Node *head_2 ) {
    Node *head = nullptr, *tail = nullptr;
    Node *curr_1 = head_1;
    Node *curr_2 = head_2;

    while( curr_1 != nullptr and curr_2 != nullptr ) {
        if( curr_1 -> val < curr_2 -> val ) {
            if( head == nullptr )
                head = tail = curr_1;
            else {
                tail -> next = curr_1;
                tail = curr_1;
            }
            curr_1 = curr_1 -> next;
        } else {
            if( head == nullptr )
                head = tail = curr_2;
            else {
                tail -> next = curr_2;
                tail = curr_2;
            }
            curr_2 = curr_2 -> next;
        }
    }

    if( curr_1 != nullptr )
        tail -> next = curr_1;
    else 
        tail -> next = curr_2;

    return head;
}

void print( Node *head ) {
    Node *current = head;
    cout << endl;
    while( current != nullptr ) {
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}


int main() {

    int test_cases, size_1, size_2, value;
    cin >> test_cases;
    while( test_cases-- ) {
        Node *head_1 = nullptr, *head_2 = nullptr;
        Node *tail_1 = nullptr, *tail_2 = nullptr;

        cin >> size_1;
        while( size_1-- ) {
            cin >> value;
            Node *new_node = new Node( value );
            if( head_1 == nullptr )
                head_1 = tail_1 = new_node;
            else {
                tail_1 -> next = new_node;
                tail_1 = new_node;
            }
        }

        cin >> size_2;
        while( size_2-- ) {
            cin >> value;
            Node *new_node = new Node( value );
            if( head_2 == nullptr )
                head_2 = tail_2 = new_node;
            else {
                tail_2 -> next = new_node;
                tail_2 = new_node;
            }
        }

        print( head_1 );
        print( head_2 );
        print( merge( head_1, head_2 ) );
    }
    return 0;
}