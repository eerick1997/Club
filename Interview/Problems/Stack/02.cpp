#include <bits/stdc++.h>

using namespace std;

stack< int > StackSort(stack<int> &Stack){

    stack<int> AStack;
    
    while( !Stack.empty() ){
        int aux = Stack.top();
        Stack.pop();
        
        while( !AStack.empty() && AStack.top() > aux ){
 
            Stack.push( AStack.top() );
            AStack.pop();    

        }

        AStack.push( aux );
    }
    return AStack;
}

int main(){
    stack<int> Stack;
    int n, v;
    cin >> n;
    while(n--){
        cin >> v;
        Stack.push(v); 
    } 

    Stack = StackSort( Stack );

    while( !Stack.empty() ){
        cout << Stack.top() << endl;
        Stack.pop();
    }

    return 0;
}