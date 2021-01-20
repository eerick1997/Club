#include <bits/stdc++.h>

using namespace std;

int leftMostColumWithAtLeastAOne(vector<vector<int>> &grid) {
    const int maxRow = grid.size();
    const int maxCol = grid[0].size();

    int row = 0, col = maxCol - 1;
    int index = -1;
    while(row < maxRow and col >= 0) {
        if(grid[row][col] == 0)
            row++;
        else
            index = col, col--;
    }
    return index;
}

int main() {
    vector<vector<int>> grid = {{0,0,0},    
                                {0,0,0},
                                {0,0,0}};

    cout << leftMostColumWithAtLeastAOne(grid) << endl;
}