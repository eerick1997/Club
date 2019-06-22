#include <bits/stdc++.h>

using namespace std;

int main(){
    
    queue<string> Queue;
    string str1, str2;
    int n;
    cin >> n;
    Queue.push("1");
    for(int i = 0; i < n; i++){
        str1 = Queue.front();
        str2 = Queue.front();
        Queue.pop();
        cout << str1 << endl;
        str1 += "0";
        str2 += "1";
        Queue.push(str1);
        Queue.push(str2);
    }
    return 0;
}