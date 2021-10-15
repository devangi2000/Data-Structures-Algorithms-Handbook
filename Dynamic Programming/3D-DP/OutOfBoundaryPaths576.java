// There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
// You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the
//  grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the
//  ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

// Example 1:
// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6
// Example 2:
// Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// Output: 12

// Constraints:
// 1 <= m, n <= 50
// 0 <= maxMove <= 50
// 0 <= startRow < m
// 0 <= startColumn < n

class Solution {
    int mod = 1000000007;    
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[][] = new int[m][n];
        dp[startRow][startColumn] = 1;
        int count = 0;
        for(int moves = 1; moves <= maxMove; moves++){
            int[][] temp = new int[m][n];
            for(int i=0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(i == m-1) count = (count + dp[i][j]) % mod;
                    if(j == n-1) count = (count + dp[i][j]) % mod;
                    if(i == 0) count = (count + dp[i][j]) % mod;
                    if(j == 0) count = (count + dp[i][j]) % mod;
                    temp[i][j] = (((i > 0 ? dp[i-1][j] : 0) + (i < m - 1 ? dp[i+1][j] : 0)) % mod
                                 + ((j > 0 ? dp[i][j-1] : 0) + (j < n - 1 ? dp[i][j+1] : 0)) % mod) % mod;
                }
            }
            dp = temp;
        }
        return count;
    }
}
