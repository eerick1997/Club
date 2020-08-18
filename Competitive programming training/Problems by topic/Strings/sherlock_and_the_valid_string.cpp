#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int difference;
    vector<int> frequencies(26, 0);
    set<int> unique_frequencies;

    for(const char c : s)
        frequencies[c - 'a']++;

    for(const int n : frequencies)
        if(n != 0)
            unique_frequencies.insert(n);

    if(unique_frequencies.size() > 2)
        return "NO";
    
    
    auto first_element = unique_frequencies.begin();
    auto second_element = unique_frequencies.begin()++;
    cout << *first_element << endl;
    cout << *second_element << endl;
    difference = *second_element - *first_element;
    cout << difference << endl;
    return (difference <= 1 ? "YES" : "NO");
}


int main() {
    string s;
    cin >> s;
    cout << isValid(s) << endl;
    return 0;
}