#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;
    node(){
        next = nullptr;
    }
};

int CompareLists( node* headA, node *headB ) {
    node *currentA = headA;
    node *currentB = headB;
    while( currentA and currentB ){
        if( currentA -> val != currentB -> val )
            return false;
        currentA = currentA -> next;
        currentB = currentB -> next;
    }
    if( currentA and !currentB )
        return false;
    if( !currentA and currentB )
        return false;
    return true;
}

int main() {
    int test_cases, n, m, in;

    cin >> test_cases;
    while( test_cases-- ) {
        node *head_1, *head_2, *tail_1, *tail_2;
        head_1 = head_2 = tail_1 = tail_2 = nullptr;

        cin >> n;
        while( n-- ) {
            node *current = new node();
            cin >> current -> val;
            if( head_1 == nullptr )
                head_1 = current;
            else 
                tail_1 -> next = current;
            tail_1 = current;
        }

        cin >> m;
        while( m-- ) {
            node *current = new node();
            cin >> current -> val;
            if( head_2 == nullptr )
                head_2 = current;
            else 
                tail_2 -> next = current;
            tail_2 = current;
        }

        cout << CompareLists( head_1, head_2 ) << endl;;
    }
}