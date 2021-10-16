// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0. 

// Example 1:

// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

class Solution {
public:
    int count = 0, max_count=INT_MIN;
    void BFS(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) return;
        if(grid[i][j]==1)
        {
            count++;
            grid[i][j]=0;
        }        
        BFS(grid,i-1, j);
        BFS(grid,i+1, j);
        BFS(grid,i, j-1);
        BFS(grid,i, j+1);        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    count=0;
                    BFS(grid, i, j);
                }
                max_count = count > max_count? count: max_count;
            }
        }
        return max_count;
    }
};
