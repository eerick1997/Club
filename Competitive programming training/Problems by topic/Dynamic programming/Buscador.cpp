#include <bits/stdc++.h>

using namespace std;

string criteria, word;
int n_words;
int DP[105][105];
bool visited[105][105];

void init_visited() {
    for(int i = 0; i < 105; i++)
        for(int j = 0; j < 105; j++)
            visited[i][j] = false;
}

int LCS(int i_1, int i_2) {
    if(i_1 == criteria.size() or i_2 == word.size())
        return 0;

    if(visited[i_1][i_2])
        return DP[i_1][i_2];

    if(criteria[i_1] == word[i_2]) {
        visited[i_1][i_2] = true;
        return DP[i_1][i_2] = LCS(i_1 + 1, i_2 + 1) + 1; 
    }

    int move_1 = LCS(i_1 + 1, i_2);
    int move_2 = LCS(i_1, i_2 + 1);

    visited[i_1][i_2] = true;
    return DP[i_1][i_2] = max(move_1, move_2);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    string string_ans = "";
    int ans = 0, cur = 0;
    cin >> criteria >> n_words;

    for(int i = 0; i < n_words; i++) {
        cin >> word;
        cur = LCS(0, 0);
        if(cur > ans)
            ans = cur, string_ans = word;
        else if(cur == ans and word.size() < string_ans.size())
            ans = cur, string_ans = word;

        init_visited();
    }
    cout << string_ans << endl;
}