#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int ans = 0;
    vector<int> bucket_a(26, 0), bucket_b(26, 0);

    for(const char c : a)
        bucket_a[c - 'a']++;
    for(const char c : b)
        bucket_b[c - 'a']++;

    for(int i = 0; i < 26; i++)
        ans += abs(bucket_a[i] - bucket_b[i]);

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << makeAnagram(a, b) << endl;
    return 0;
}