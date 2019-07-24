class Solution {

private:
    int ans;

public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        
        int sx = 0, sy = 0, freeSquare = 1;
        ans = 0;
        //Find the free squares and the position of the square where we go to start
        for( int i = 0; i < grid.size(); i++ ){
            for(int j = 0; j < grid[0].size(); j++){
                if( grid[i][j] == 0 )
                    freeSquare++;
                if( grid[i][j] == 1 )
                    sx = i, sy = j;
            }
        }
        findPath(sx, sy, freeSquare, grid);
        return ans;
    }

    void findPath( int x, int y, int freeSquares, vector<vector<int>> &grid){
    
        //Out of range, negative indexes
        if( x < 0 || y < 0 )
            return;
        //Out of range, indexes doesn't exist
        if( x >= grid.size() || y >= grid[0].size() )
            return;

        if( grid[x][y] == -1 )
            return;

        if( grid[x][y] == 2 ){
            if( freeSquares == 0 )
                ans++;
            return;    
        }

        //To the next recursions we need to drop the current element
        grid[x][y] = -1;

        findPath( x + 1, y, freeSquares - 1, grid );
        findPath( x - 1, y, freeSquares - 1, grid );
        findPath( x, y + 1, freeSquares - 1, grid );
        findPath( x, y - 1, freeSquares - 1, grid );
        //To the end of the recursion the other recursion calls need to have free the current element
        grid[x][y] = 0;
    }

};