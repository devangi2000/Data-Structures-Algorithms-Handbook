// Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

// A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

 

// Example 1:


// Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
// Output: 13
// Explanation: 
// The possible falling paths are:
// [1,5,9], [1,5,7], [1,6,7], [1,6,8],
// [2,4,8], [2,4,9], [2,6,7], [2,6,8],
// [3,4,8], [3,4,9], [3,5,7], [3,5,9]
// The falling path with the smallest sum is [1,5,7], so the answer is 13.
// Example 2:

// Input: grid = [[7]]
// Output: 7
 

// Constraints:

// n == grid.length == grid[i].length
// 1 <= n <= 200
// -99 <= grid[i][j] <= 99

class Solution {    
    public int solve(int[][] grid, int[][] dp, int i, int j){
        if(i == grid.length)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int temp = Integer.MAX_VALUE;
        for(int k = 0; k < grid[0].length; k++){
            if(k == j) continue;
            int curr = solve(grid, dp, i + 1, k);
            temp = Math.min(temp, curr);
        }
        if(temp != Integer.MAX_VALUE) temp += grid[i][j];
        return dp[i][j] = temp;
    }
    
    public int minFallingPathSum(int[][] grid) {
        if(grid[0].length == 1) return grid[0][0];
        int[][] dp = new int[grid.length][grid[0].length];
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < grid.length; i++)
            Arrays.fill(dp[i], -1);
        for(int i = 0; i < grid[0].length; i++)
            ans = Math.min(ans, solve(grid, dp, 0, i));
        return ans;
    }
}

