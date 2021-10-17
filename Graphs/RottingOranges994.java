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
    public int orangesRotting(int[][] grid) {
        int rows = grid.length, cols = grid[0].length, timer = 0, fresh = 0;
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    int[] temp = {i, j};
                    q.add(temp);
                }
                else if(grid[i][j] == 1)
                    fresh++;        
         }
        }
        if(fresh == 0) return 0;
        while(!q.isEmpty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
            int[] x = q.poll();
            int r = x[0], c = x[1];
            if(r > 0 && grid[r-1][c] == 1){
                grid[r-1][c] = 2;
                fresh--;
                int[] temp = {r-1, c};
                q.add(temp);
            }
            if(c > 0 && grid[r][c-1] == 1){
                grid[r][c-1] = 2;
                fresh--;
                int[] temp = {r, c-1};
                q.add(temp);
            }
            if(r < rows - 1 && grid[r+1][c] == 1){
                grid[r+1][c] = 2;
                fresh--;
                int[] temp = {r+1, c};
                q.add(temp);
            }
            if(c < cols - 1 && grid[r][c+1] == 1){
                grid[r][c+1] = 2;
                fresh--;
                int[] temp = {r, c+1};
                q.add(temp);
            }
          }
            timer++;
        }
        return fresh > 0 ? -1 : timer - 1;
    }
}



        