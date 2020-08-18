#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, i;
    string str;
    bool ans = true;

    cin >> n;
    while(n--) {
        stack<char> Stack;
        cin >> str;
        for(i = 0; i < str.size(); i++) {
            const char c = str[i];
            if(c == '(' or c == '[' or c == '{')    
                Stack.push(c);
            else if(c == ')' and !Stack.empty() and Stack.top() == '(')
                Stack.pop();
            else if(c == ']' and !Stack.empty() and Stack.top() == '[')
                Stack.pop();
            else if(c == '}' and !Stack.empty() and Stack.top() == '{')
                Stack.pop();
            else 
                break;
        }
        cout << (!Stack.size() and i == str.size() ? "YES" : "NO") << endl;
    }
    return 0;
}