#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

bool ge(const string a, const string b) {
    string A = a + b;
    string B = b + a;
    return A.compare(B) > 0 ? 1 : 0;
}

bool sort_func(const string a, const string b) {
    return ge(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    lli n;
    vector<string> numbers;
    string buffer;
    cin >> n;
    numbers.resize(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
        sort(begin(numbers[i]), end(numbers[i]));
        reverse(begin(numbers[i]), end(numbers[i]));    
    }
    sort(begin(numbers), end(numbers), sort_func);
    
    for(string number : numbers)
        cout << number;
    
    cout << endl;
    return 0;
}