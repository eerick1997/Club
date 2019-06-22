#include <bits/stdc++.h>

using namespace std;

struct Stack{

    int size;
    queue<int> Queue;

    Stack(){
        size = 0;
    }

    void Push( int val ){
        queue<int> result;
        result.push( val );
        while( !Queue.empty() ){
            result.push( Queue.front() );
            Queue.pop();
        }
        Queue = result;
        size++;
    }

    void Pop(){
        if( size > 0 ){
            Queue.pop();
            size--;
        } else {
            cout << "\nStack doesn't have elements\n";
        }
    }

    int Top(){
        return Queue.front();
    }

    int GetSize(){
        return size;
    }

    bool IsEmpty(){
        return ( size == 0 );
    }
};

int main(){
    Stack *stack = new Stack();
    int n, v;
    cin >> n;
    while(n--){
        cin >> v;
        stack -> Push( v );
    }

    while( !stack ->  IsEmpty() ){
        cout << endl << stack -> Top() << endl;
        stack -> Pop();
    }
    return 0;
}