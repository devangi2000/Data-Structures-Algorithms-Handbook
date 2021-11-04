// You are given an m x n integer array grid where grid[i][j] could be:

// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

// Example 1:


// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:


// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:


// Input: grid = [[0,1],[2,0]]
// Output: 0
// Explanation: There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 20
// 1 <= m * n <= 20
// -1 <= grid[i][j] <= 2
// There is exactly one starting cell and one ending cell.

class Solution {
public:
    int ans = 0;
    vector<int> dirs = {0, 1, 0, -1, 0};
    void dfs(vector<vector<int>> &grid, int r, int c, int cells){
        if(r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size() or grid[r][c] == -1 or grid[r][c] == 3)
            return;
        if(grid[r][c] == 2){
            if(cells == 0) ans++;
            return;
        }
        grid[r][c] = 3;
        cells -= 1;
        dfs(grid, r+1, c, cells);
        dfs(grid, r-1, c, cells);
        dfs(grid, r, c+1, cells);
        dfs(grid, r, c-1, cells);
        grid[r][c] = 0;
        cells += 1;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow, startCol, cellsToVisit = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) startRow = i, startCol = j;
                else if(grid[i][j] != -1) cellsToVisit++;
        dfs(grid, startRow, startCol, cellsToVisit);
        return ans;
    }
};

