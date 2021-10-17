// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q; // to store the indices of the rotten oranges
        int fresh_oranges = 0, timer_count = 0;
        // initially insert all the indices with rotten oranges into the queue
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j])
                    fresh_oranges++;
            }
        }
        // no fresh oranges so return 0
        if(!fresh_oranges) return 0;
        // else apply BFS
       while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto [r, c] = q.front();
                q.pop();
                // recursive dfs calls in 4 directions
                // we only make a call if the neighbour exist and is a fresh orange
                if(r > 0 and grid[r - 1][c] == 1) {
                    // make the fresh orange rotten
                    grid[r - 1][c] = 2;
                    // decrease the fresh count by 1
                    fresh_oranges--;
                    // push it in the queue
                    q.push({r - 1, c}); // q.emplace(r-1, c);
                }
                if(r + 1 < rows and grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    fresh_oranges--;
                    q.push({r + 1, c}); // q.emplace(r+1, c);
                }
                if(c > 0 and grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    fresh_oranges--;
                    q.push({r, c - 1}); // q.emplace(r, c-1);
                }
                if(c + 1 < cols and grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    fresh_oranges--;
                    q.push({r, c + 1}); // q.emplace(r, c+1);
                }
            }
            timer_count++;
        }
        return fresh_oranges > 0 ? -1 : timer_count - 1;
    }
};