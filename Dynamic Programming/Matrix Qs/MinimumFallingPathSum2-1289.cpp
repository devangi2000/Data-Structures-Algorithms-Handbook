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
public:
    
    int solve(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j){
        if(i == grid.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = 0; k < grid[0].size(); k++){
            if(k == j) continue;
            int curr = solve(grid, dp, i + 1, k);
            mini = min(mini, curr);
        }
        if(mini != INT_MAX) mini += grid[i][j];
        return dp[i][j] = mini;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        if(grid[0].size() == 1) return grid[0][0];
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++)
            ans = min(ans, solve(grid, dp, 0, i));
        return ans;
    }
};