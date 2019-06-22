#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<int> Queue;
    stack<int> Stack;
    int n, v, k;
    cin >> n;
    while(n--){
        cin >> v;
        Queue.push(v);
    }

    cin >> k;

    for (int i = 0; i < k; i++){
        Stack.push( Queue.front() );
        Queue.pop();
    }

    while( !Stack.empty() ){
        Queue.push( Stack.top() );
        Stack.pop();
    }

    for(int i = 0; i < Queue.size() - k; i++){
        Queue.push( Queue.front() );
        Queue.pop();
    }

    while( !Queue.empty() ){
        cout << Queue.front() << " ";
        Queue.pop();
    }
    
    return 0;
}