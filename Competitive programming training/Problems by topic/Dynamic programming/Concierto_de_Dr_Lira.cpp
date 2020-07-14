#include <bits/stdc++.h>

using namespace std;

int changes, initial, maximum;
vector<int> volume_changes;
int DP[1005][1005];
bool visited[1005][1005];

int solve(int index, int current) {

    if(current < 0)
        return -1;

    if(current > maximum)
        return -1;

    if(index == changes)
        return current;

    if(visited[index][current])
        return DP[index][current];

    int sub, add;
    sub = solve(index + 1, current - volume_changes[index]);
    add = solve(index + 1, current + volume_changes[index]);
    
    visited[index][current] = true;
    return DP[index][current] = max(add, sub);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    cin >> changes;
    volume_changes.resize(changes);
    for(int i = 0; i < changes; i++)
        cin >> volume_changes[i];

    cin >> initial >> maximum;

    cout << solve(0, initial) << endl;
    return 0;
}