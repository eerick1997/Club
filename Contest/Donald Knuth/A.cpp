#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    string s;
    int i;
    cin >> i >> s;

    sort(s.begin(), s.end());

    cout << s << "\n";
    return 0;
}