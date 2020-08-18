#include <bits/stdc++.h>

using namespace std;

long minimumAbsoluteDifference(vector<int> &arr) {
    long ans = 1e10;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1; i++)
        ans = min(ans, labs(arr[i] - arr[i + 1]));

    return ans;
}

int main() {
    int n_numbers;
    vector<int> number;
    cin >> n_numbers;
    number.resize(n_numbers);
    for(int i = 0; i < n_numbers; i++)
        cin >> number[i];
    
    cout << minimumAbsoluteDifference(number) << endl;
}