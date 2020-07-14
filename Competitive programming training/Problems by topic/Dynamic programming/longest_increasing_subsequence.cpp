#include <bits/stdc++.h>

using namespace std;
vector<int> numbers;
int DP[1005][1005];
bool visited[1005][1005];

int solve(int index, int last) {

    if(index == numbers.size())
        return 0;
    
    if(visited[index][last])
        return DP[index][last];

    if(numbers[index] > last) {
        int take = solve(index + 1, numbers[index]) + 1;
        int not_take = solve(index + 1, last);
        visited[index][last] = true;
        return DP[index][last] = max(take, not_take);
    }

    visited[index][last] = true;
    return DP[index][last] = solve(index + 1, last);
}

int main() {
    int n;
    cin >> n;
    numbers.resize(n);
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    cout << solve(0, 0) << endl;
    return 0;
}