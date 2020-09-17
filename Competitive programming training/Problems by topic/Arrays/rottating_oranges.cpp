class Solution {
public:
   
    //This solutions is the brute force
    /*int countFreshOranges(vector<vector<int>> &grid) {
        int countFreshOranges = 0;
        for(const vector<int> row : grid)
            for(const int val : row)
                if(val == 1)
                    countFreshOranges++;
        
        return countFreshOranges;
    }
    
    void changeValueIfIsPossible(vector<vector<int>> &grid, vector<vector<int>> &nextIteration, int x, int y, int &numberFreshOranges) {
        if(x == grid.size() or y == grid[0].size())
            return;
        
        if(x < 0 or y < 0)
            return;
        
        if(grid[x][y] == 1) {
            if(nextIteration[x][y] == 1)
                numberFreshOranges--;
            nextIteration[x][y] = 2;
        }

    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        const int width = grid.size();
        const int height = grid[0].size();
        vector<vector<int>> nextIteration(grid.begin(), grid.end());
        
        int numberOfFreshOranges = countFreshOranges(grid);
        int lastNumberOfFreshOranges = INT32_MAX;
        int minimumNumberOfMinutes = 0;
        
        while(numberOfFreshOranges > 0 and numberOfFreshOranges != lastNumberOfFreshOranges) {
            lastNumberOfFreshOranges = numberOfFreshOranges;
            for(int x = 0; x < width; x++) {
                for(int y = 0; y < height; y++) {
                    const int val = grid[x][y];
                    if(val == 2) {
                        changeValueIfIsPossible(grid, nextIteration, x + 1, y, numberOfFreshOranges);
                        changeValueIfIsPossible(grid, nextIteration, x - 1, y, numberOfFreshOranges);
                        changeValueIfIsPossible(grid, nextIteration, x, y + 1, numberOfFreshOranges);
                        changeValueIfIsPossible(grid, nextIteration, x, y - 1, numberOfFreshOranges);
                    }
                }
            }
            minimumNumberOfMinutes++;
            swap(grid, nextIteration);
        }
        
        return numberOfFreshOranges == 0 ? minimumNumberOfMinutes : -1;
    }*/
    
    struct point{
        int x, y;
        
        point(){
            x = y = 0;
        }
        
        point(int x, int y) : x(x), y(y){}
    };
    
    void changeCellIfIsPossible(vector<vector<int>> &grid, int x, int y, int &numberOfFreshOranges, queue<point> &Queue) {
        if(x == grid.size() or y == grid[0].size())
            return;
        
        if(x < 0 or y < 0)
            return;
        
        if(grid[x][y] == 1) {
            grid[x][y] = 2;
            Queue.push(point(x, y));
            numberOfFreshOranges--;
        }
        
    }
    
    //Solution using BFS inside a adjacency matrix
    int orangesRotting(vector<vector<int>>& grid) {
        queue<point> Queue;
        const int width = grid.size();
        const int height = grid[0].size();
        int numberOfFreshOranges = 0;
        int time = 0;
        
        for(int x = 0; x < width; x++) {
            for(int y = 0; y < height; y++) {
                const int currentCell = grid[x][y];
                if(currentCell == 2)
                    Queue.push(point(x, y));
                else if(currentCell == 1)
                    numberOfFreshOranges++;
            }
        }
        
        point currentCell;
        int currentRottenOrangesSize = 0;
        while(!Queue.empty() and numberOfFreshOranges > 0) {
            currentRottenOrangesSize = Queue.size();
            while(currentRottenOrangesSize-- > 0) {
                currentCell = Queue.front();
                Queue.pop();
                changeCellIfIsPossible(grid, currentCell.x + 1, currentCell.y, numberOfFreshOranges, Queue);
                changeCellIfIsPossible(grid, currentCell.x - 1, currentCell.y, numberOfFreshOranges, Queue);
                changeCellIfIsPossible(grid, currentCell.x, currentCell.y + 1, numberOfFreshOranges, Queue);
                changeCellIfIsPossible(grid, currentCell.x, currentCell.y - 1, numberOfFreshOranges, Queue);
            }
            time++;
        }
        
        cout << numberOfFreshOranges << endl;
        return (numberOfFreshOranges == 0 ? time : -1);
    }
};