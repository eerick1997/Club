#include <bits/stdc++.h>

using namespace std;

int DP[100005];
bool visited[100005];

int solve(int i, vector<int> &arr) {
    if(i >= arr.size())
        return 0;
    
    if(visited[i])
        return DP[i];

    int take_current = solve(i + 2, arr) + arr[i];
    int take_next = solve(i + 1, arr);

    visited[i] = true;
    return DP[i] = max(take_current, take_next);
}

int maxSubsetSum(vector<int> &arr) {
    return solve(0, arr);
}

int main() {
    int n;
    vector<int> number;
    cin >> n;
    number.resize(n);
    for(int i = 0; i < n; i++)
        cin >> number[i];

    cout << maxSubsetSum(number) << endl;
}