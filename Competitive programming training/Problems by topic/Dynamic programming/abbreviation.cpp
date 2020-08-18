#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> DP;
vector<vector<bool>> visited;

string a, b;

int solve(int i, int j) {

    
    if(i == a.size() or j == b.size())
        return 0;
    
    if(visited[i][j])
        return DP[i][j];

    if(a[i] == b[i] or toupper(a[i]) == b[j]) {
        visited[i][j] == true;
        return DP[i][j] = solve(i + 1, j + 1) + 1;
    }

    visited[i][j] = true;
    return DP[i][j] = isupper(a[i]) ? 0 : solve(i + 1, j);
}

void print_dp() {
    cout << endl;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++)
            cout << DP[i][j] << " ";
        cout << endl;
    }
}

string abbreviation(string a, string b) {
    if(a.size() < b.size())
        return "NO";

    cout << "\nsolve = " << solve(0, 0) << endl;
    print_dp();
    return solve(0, 0) == b.size() ? "YES" : "NO";
}

int main() {
    int n_queries;
    cin >> n_queries;
    while(n_queries--) {
        DP.assign(1005, vector<int>(1005, 0));
        visited.assign(1005, vector<bool>(1005, false));
        cin >> a >> b;
        cout << abbreviation(a, b) << endl;
        visited.clear();
        DP.clear();
    }

    return 0;
}