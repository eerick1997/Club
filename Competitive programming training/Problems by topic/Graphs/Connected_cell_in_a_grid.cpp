#include <bits/stdc++.h>

using namespace std;


int helper(int x, int y, vector<vector<int>> &grid) {
    if(x == grid.size() or x < 0)
        return 0;
    
    if(y == grid[0].size() or y < 0)
        return 0;

    if(grid[x][y] == 0)
        return 0;
    
    grid[x][y] = 0;
    int N = helper(x, y + 1, grid);
    int S = helper(x, y - 1, grid);
    int E = helper(x + 1, y, grid);
    int W = helper(x - 1, y, grid);
    int NE = helper(x + 1, y + 1, grid);
    int NW = helper(x + 1, y - 1, grid);
    int SE = helper(x - 1, y + 1, grid);
    int SW = helper(x - 1, y - 1, grid);

    return N + S + E + W + NE + NW + SE + SW + 1;
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    
    int ans = 0;
    for(int x = 0; x < grid.size(); x++)
        for(int y = 0; y < grid[0].size(); y++)
            ans = max(ans, helper(x, y, grid));
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
