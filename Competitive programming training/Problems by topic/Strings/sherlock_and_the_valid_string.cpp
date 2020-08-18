#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string &s) {
    vector<long> frequencies(26, 0);
    long begin = 0;
    bool flag = true;
    for(const char c : s)
        frequencies[c - 'a']++;
    
    sort(frequencies.begin(), frequencies.end());

    while(frequencies[begin] == 0)
        begin++;

    if(frequencies[begin] != 1 and frequencies[25] - frequencies[begin] > 1)
        return "NO";
    
    
    for(long i = begin; i < 25; i++)
        if(frequencies[i] != frequencies[i + 1])
            flag = false;

    if(flag) return "YES";

    flag = true;
    frequencies[begin]--;
    for(long i = begin; i < 25; i++)
        if(frequencies[i] != 0 and frequencies[i] != frequencies[i + 1])
            flag = false;

    if(flag) return "YES";
    
    flag = true;    
    frequencies[begin]++, frequencies[25]--;
    for(long i = begin; i < 25; i++)
        if(frequencies[i] != frequencies[i + 1])
            flag = false;

    return (flag ? "YES" : "NO");
}


int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}