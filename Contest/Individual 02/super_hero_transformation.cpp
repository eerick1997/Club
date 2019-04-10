#include<bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(){
    bool ans = true;
    string s, t;
    cin >> s >> t;

    if(s.size() != t.size())
        ans = false;

    for(int i = 0; i < s.size(); i++){
        if( ( isVowel(s[i]) && !isVowel(t[i]) ) ||  ( isVowel(t[i]) && !isVowel(s[i]) ) )
            ans = false;
    }
        
    cout << ((ans) ? "Yes" : "No") << endl;
}