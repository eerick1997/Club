#include <bits/stdc++.h>

using namespace std;

//Finding a recursive solution :'v Dynamic Programming
int maxPalindromicSubstring(string &s, int start, int end, vector<vector<int>> &DP) {
    if(start == s.size() or end == s.size())
        return 0;
    if(start == end)
        DP[start][end] = 1;


    if(s[start] == s[end]){

    }

}

//Iterative solution using Dynamic Programming
int maxPalindromicSubstring(string &s, vector<vector<int>> &DP) {
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
        DP[i][i] = 1, ans = max(ans, DP[i][i]);
    
    for(int i = 0; i < n - 1; i++)
        if(s[i] == s[i + 1])
            DP[i][i + 1] = 2, ans = max(ans, DP[i][i + 1]);

    for(int length = 2; length < n; length++) {
        for(int start = 0; (start + length) < n; start++) {
            int end = start + length;
            if(s[start] == s[end] and DP[start + 1][end - 1] > 0)
                DP[start][end] = (end - start) + 1, ans = max(ans, DP[start][end]);
        }
    }

    return ans;
}

int main() {
    string s;
    int ans = 0;
    vector<vector<int>> DP;
    cin >> s;
    DP.assign(s.size(), vector<int>(s.size(), 0));

    //cout << maxPalindromicSubstring(s, 0, s.size() - 1, DP) << endl;
    cout << maxPalindromicSubstring(s, DP) << endl;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++)
            cout << DP[i][j] << " ";
        cout << endl;
    }

    return 0;
}