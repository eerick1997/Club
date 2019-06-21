#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *previous;
    int value;

    Node(int _value){
        value = _value;
        previous = NULL;
    }
};

struct Stack {

    Node *top;
    int size;

    Stack(){
        top = NULL;
        size = 0;
    }

    void Push(int value){
        Node *node = new Node( value );
        if( size == 0 )
            top = node;
        else {
            node -> previous = top;
            top = node;
        }
        size++;
    }

    int Pop(){
        int v_return = INT_MIN;
        if( size > 0){

            v_return = top -> value;
            top = top -> previous;
            size--;

        } else {
            cout << "\nStack is empty \n";
        } 

        return v_return;
    }

    bool IsEmpty(){
        return (size == 0);
    }

    int Top(){
        return top -> value;
    }

    int GetSize(){
        return size;
    }


};


int main(){

    Stack *stack = new Stack();

    stack -> Push(0);
    cout << stack -> Top() << endl;
    stack -> Push(1);
    cout << stack -> Top() << endl;
    stack -> Push(2);
    cout << stack -> Top() << endl;
    stack -> Push(3);
    cout << stack -> Top() << endl;
    cout << "Current size " << stack -> GetSize() << endl;
    cout << stack -> Pop() << endl;
    cout << "Current size " << stack -> GetSize() << endl;
    cout << "Top " << stack -> Top() << endl;
    return 0;
}