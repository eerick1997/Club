#include <bits/stdc++.h>

using namespace std;

int main(){
    stack< char > Stack;
    string s;
    cin >> s;

    for( auto c : s ){
        if(c == '('){
            Stack.push(c);
        } else {
            Stack.pop();
        }
    }

    cout << ( Stack.size() == 0 ? "Balanced" : "Not balanced" ) << endl;
    
    return 0;
}