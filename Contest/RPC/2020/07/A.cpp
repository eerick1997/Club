#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

int n_on_segments[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

vector<lli> DP(1000005);
bool visited[1000005];

lli ans = 0;

lli solve(lli current_energy, lli curr_value) {
    if(current_energy < 0)
        return 0;
    
    if(current_energy == 0)
        return curr_value;
    
    if(visited[current_energy])
        return DP[current_energy];

    for(int i = 0; i <= 9; i++)
        DP[current_energy] = solve(current_energy - i, curr_value + n_on_segments[i]);
    
    visited[current_energy] = true;
    return DP[current_energy];
}


int main() {
    lli n_segments;
    cin >> n_segments;
    cout << solve(n_segments, 0) << endl;
    return 0;
}