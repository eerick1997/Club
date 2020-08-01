#include <bits/stdc++.h>

using namespace std;

int main() {

    string input;
    cin >> input;
    for(char c : input) {
        if(c == 'O' or c == 'o')
            cout << 0;
        else if(c == 'I' or c == 'i')
            cout << 1;
        else if(c == 'z' or c == 'Z')
            cout << 2;
        else if(c == 'e' or c == 'E')
            cout << 3;
        else if(c == 'a' or c == 'A')
            cout << 4;
        else if(c == 's' or c == 'S')
            cout << 5;
        else if(c == 'g' or c == 'G')
            cout << 6;
        else if(c == 't' or c == 'T')
            cout << 7;
        else if(c == 'b' or c == 'B')
            cout << 8;
        else
            cout << c;
    }
    cout << endl;
    
}