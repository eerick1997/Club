#include <bits/stdc++.h>

using namespace std;

int alternatingCharacters(string &s) {
    int ans = 0;
    for(int i = 0; i < s.size() - 1; i++)
        if(s[i] == s[i + 1])
            ans++;
    
    return ans;
}

int main() {
    int n_queries;
    string str;
    cin >> n_queries;
    while(n_queries--){
        cin >> str;
        cout << alternatingCharacters(str) << endl;
    }
    return 0;
}