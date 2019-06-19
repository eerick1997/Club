#include <bits/stdc++.h>

using namespace std;

int msolution(vector<vector<int>> &grid, int x, int y){
    cout << "\t(" << x << "," << y << "), ";
    if(grid[x][y] == 2)
        return 1;
    if(grid[x][y] == -1)
        return 0;
    if( !(0 <= x && x < grid.size() - 1) )
        return 0;
    if( !(0 <= y && y < grid[0].size() - 1) )
        return 0;
    else {
        int a = msolution(grid, x + 1, y);
        cout << endl;
        a += msolution(grid, x, y + 1);
        return a;
    }
}

int main(){
    vector<vector<int>> grid;
    int m, n;
    cin >> n >> m;
    grid.resize( m, vector<int>(n) );
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        cout << endl;
        for(int j = 0; j < n; j++)
            cout << grid[i][j] << "\t";
    }

    cout << endl;
    cout << msolution(grid, 0, 0) << endl;


    return 0;
}