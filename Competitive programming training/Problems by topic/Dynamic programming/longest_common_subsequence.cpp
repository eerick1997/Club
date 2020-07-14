#include<bits/stdc++.h>

using namespace std;

string str1, str2;
int DP[1005][1005];
bool visited[1005][1005];

int LCS(int i_1, int i_2) {
    if(i_1 == str1.size() or i_2 == str2.size())
        return 0;

    if(visited[i_1][i_2])
        return DP[i_1][i_2];

    if(str1[i_1] == str2[i_2]) {
        visited[i_1][i_2] = true;
        return DP[i_1][i_2] = LCS(i_1 + 1, i_2 + 1) + 1; 
    }

    int move_1 = LCS(i_1 + 1, i_2);
    int move_2 = LCS(i_1, i_2 + 1);

    visited[i_1][i_2] = true;
    return DP[i_1][i_2] = max(move_1, move_2);
}

int main() {
    str1 = "AGPGTAB";
    str2 = "GXTXAYB";
    cout << LCS(0, 0) << endl;
    return 0;
}