#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> DP;
vector<vector<bool>> visited;

string a, b;

bool hasUpperCaseLetters(int begin) {
    for(int i = begin; i < a.size(); i++)
        if(isupper(a[i]))
            return true;
    return false;
}

int solve(int index_a, int index_b) {

    //Check if at right we have uppercase letters
    if(index_b == b.size())
        return !hasUpperCaseLetters(index_a);

    if(index_a == a.size())
        return false;

    if(isupper(a[index_a]) and a[index_a] != b[index_b])
        return false;

    //We already calculated the current subproblem    
    if(visited[index_a][index_b])
        return DP[index_a][index_b];

    if(a[index_a] == b[index_b] or toupper(a[index_a]) == b[index_b]) {
        visited[index_a][index_b] = true;
        int ignore = (isupper(a[index_a]) ? false : solve(index_a + 1, index_b));
        return DP[index_a][index_b] = solve(index_a + 1, index_b + 1) or ignore;
    }

    visited[index_a][index_b] = true;
    return DP[index_a][index_b] = solve(index_a + 1, index_b);
}

string abbreviation(string a, string b) {
    if(a.size() < b.size())
        return "NO";
    return solve(0, 0) ? "YES" : "NO";
}

int main() {
    int n_queries;
    cin >> n_queries;
    while(n_queries--) {
        DP.assign(1005, vector<bool>(1005, false));
        visited.assign(1005, vector<bool>(1005, false));
        cin >> a >> b;
        cout << abbreviation(a, b) << endl;
        visited.clear();
        DP.clear();
    }

    return 0;
}