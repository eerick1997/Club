#include <iostream>
#include <stack>

using namespace std;

bool is_balanced(string expression) {
    stack<char> s;
    
    for(auto c: expression){
        if(c == '(' || c == '[' || c == '{'){
            s.push(c);
        } else {
            if(s.empty())
                return false;
            else if(c == ')' && s.top() == '(')
                s.pop();
            else if(c == ']' && s.top() == '[')
                s.pop();
            else if(c == '}' && s.top() == '{')
                s.pop();
        }
    }
    return(s.empty());
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
