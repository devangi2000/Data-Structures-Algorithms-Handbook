// You are given an m x n integer matrix grid, and three integers row, col, and color. 
// Each value in the grid represents the color of the grid square at that location.
// Two squares belong to the same connected component if they have the same color and 
// are next to each other in any of the 4 directions.
// The border of a connected component is all the squares in the connected component that
// are either 4-directionally adjacent to a square not in the component, or on the boundary
//  of the grid (the first or last row or column).
// You should color the border of the connected component that contains the square
//  grid[row][col] with color.
// Return the final grid.

// Example 1:
// Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
// Output: [[3,3],[3,2]]
// Example 2:
// Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
// Output: [[1,3,3],[2,3,3]]
// Example 3:
// Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
// Output: [[2,2,2],[2,1,2],[2,2,2]]
//  Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// 1 <= grid[i][j], color <= 1000
// 0 <= row < m
// 0 <= col < n

class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, int color){
        if(r < 0 or r >= grid.size() or c < 0 or c >= grid[r].size() or grid[r][c] != color)
            return;
        grid[r][c] = -color;
        dfs(grid, r + 1, c, color);
        dfs(grid, r - 1, c, color);
        dfs(grid, r, c + 1, color);
        dfs(grid, r, c - 1, color);
        if(r > 0 and c > 0 and r < grid.size()-1 and c < grid[r].size()-1 and 
          abs(grid[r+1][c]) == color and abs(grid[r-1][c]) == color and abs(grid[r][c+1]) == color
          and abs(grid[r][c-1]) == color)
            grid[r][c] = color;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        dfs(grid, r0, c0, grid[r0][c0]);
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                grid[i][j] = grid[i][j] < 0 ? color : grid[i][j];
        return grid;
    }
};

