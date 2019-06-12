#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    double P = 0, ans = 0;
    cin >> s >> P;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1')
            ans += 1.0;
        else if(s[i] == '?')
            ans += P;
    }

    cout << std::fixed << std::setprecision(5) << (double)(ans / s.size()) << endl;
    return 0;
}