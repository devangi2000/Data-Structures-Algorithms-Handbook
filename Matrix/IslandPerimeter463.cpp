// You are given row x col grid representing a map where grid[i][j] = 1 represents 
// land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely 
// surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around
//  the island. One cell is a square with side length 1. The grid is rectangular, width and 
//  height don't exceed 100. Determine the perimeter of the island.
// Example 1:
// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:
// Input: grid = [[1]]
// Output: 4
// Example 3:
// Input: grid = [[1,0]]
// Output: 4 

// Constraints:
// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] is 0 or 1.
// There is exactly one island in grid.


// METHOD 1
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size(), ans=0;
        if(n==0 || m==0) return 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=4;
                    if(i>0)
                    {
                        if(grid[i-1][j]==1) ans--;
                    }
                    if(i<n-1)
                    {
                        if(grid[i+1][j]==1) ans--;
                    }
                    if(j>0)
                    {
                        if(grid[i][j-1]==1) ans--;
                    }
                    if(j<m-1)
                    {
                        if(grid[i][j+1]==1) ans--;
                    }
                }
            }
        }
        return ans;
    }
};


// METHOD 2
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    ans += 4;
                    ans -= (i > 0 && grid[i-1][j] == 1) ? 1 : 0;
                    ans -= (i < n - 1 && grid[i+1][j] == 1) ? 1 : 0;
                    ans -= (j > 0 && grid[i][j-1] == 1) ? 1 : 0;
                    ans -= (j < m - 1 && grid[i][j+1] == 1) ? 1 : 0;
                }
            }
        }
        return ans;
    }
};