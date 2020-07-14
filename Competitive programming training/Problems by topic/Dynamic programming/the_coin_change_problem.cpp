#include <bits/stdc++.h>

using namespace std;

vector<int64_t> coins;
int64_t DP[255][255];
bool visited[255][255];

int64_t solve(int64_t index, int64_t current) {

    if(current == 0) 
        return 1;

    if(index == coins.size() or current < 0)
        return 0;
        
    if(visited[index][current])
        return DP[index][current];

    int64_t not_take = solve(index + 1, current);
    int64_t take = solve(index, current - coins[index]);

    visited[index][current] = true;
    return DP[index][current] = take + not_take;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int64_t change, n_coin_types;
    cin >> change >> n_coin_types;
    coins.resize(n_coin_types);
    for( int i = 0; i < n_coin_types; i++ )
        cin >> coins[i];
    
    cout << solve(0, change) << endl;
    
    return 0;
}