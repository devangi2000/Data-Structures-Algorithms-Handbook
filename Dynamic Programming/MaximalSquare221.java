// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:

// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0


class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = matrix[0].length, largest = 0;
        if(rows == 0) return 0;
        int[][] dp = new int[rows+1][cols+1];
        for(int i = 1; i <= rows; ++i){
            for(int j = 1; j <= cols; ++j){
                if(matrix[i-1][j-1] - '0' == 1){
                    dp[i][j] = 1 + Math.min(dp[i-1][j-1], (Math.min(dp[i-1][j], dp[i][j-1])));
                    largest = Math.max(largest, dp[i][j]);
                }
            }
        }
        return largest*largest;
    }
}