#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m;
    char buffer, chessboard[105][105];
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> buffer;
            if(buffer == '.')
                chessboard[i][j] = ((i + j) & 1) ? 'B' : 'W';
            else 
                chessboard[i][j] = '-';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << chessboard[i][j];
        cout << endl;
    }
            
    return 0;
}