#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> grid;

bool search_path(int sx, int sy) {
    if(sx > grid.size() or sy > grid[0].size())
        return false;
    if(sx < 0 or sy < 0)
        return false;
    
    if(grid[sx][sy] == 'F')
        return true;
    bool up, right, down, left;
    up = search_path(sx + 1, sy);
    right = search_path(sx, sy + 1);
    down = search_path(sx - 1, sy);
    left = search_path(sx, sy - 1);
    return (up or right or down or left);
}

int main() {
    int n, m;
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j]


    return 0;
}