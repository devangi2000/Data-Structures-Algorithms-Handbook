// Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

// to the cell diagonally up towards the right 
// to the right
// to the cell diagonally down towards the right
// Find out maximum amount of gold which he can collect.


// Example 1:

// Input: n = 3, m = 3
// M = {{1, 3, 3},
//      {2, 1, 4},
//      {0, 6, 4}};
// Output: 12
// Explaination: 
// The path is {(1,0) -> (2,1) -> (2,2)}.
// Example 2:

// Input: n = 4, m = 4
// M = {{1, 3, 1, 5},
//      {2, 2, 4, 1},
//      {5, 0, 2, 3},
//      {0, 6, 1, 2}};
// Output: 16
// Explaination: 
// The path is {(2,0) -> (3,1) -> (2,2) 
// -> (2,3)} or {(2,0) -> (1,1) -> (1,2) 
// -> (0,3)}.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)


Constraints:
1 ≤ n, m ≤ 50
  1 ≤ M[i][j] ≤ 100
  
  
class Solution{
public:
    int ans = 0;
    void solve(vector<vector<int>> &dp, vector<vector<int>> &M, int row, int col){
        for(int i = col - 1; i >= 0; i--){
            for(int j = 0; j < row; j++){
                if(i == col-1)
                    dp[j][i] = M[j][i];
                else if(j == 0)
                    dp[j][i] = M[j][i] + max(dp[j+1][i+1], dp[j][i+1]);
                else if(j == row-1)
                    dp[j][i] = M[j][i] + max(dp[j-1][i+1], dp[j][i+1]);
                else
                    dp[j][i] = M[j][i] + max({dp[j+1][i+1], dp[j][i+1], dp[j-1][i+1]});
            }
        }
        
        for(int i = 0; i< row; i++)
            ans = max(ans, dp[i][0]);
    }
    int maxGold(int row, int col, vector<vector<int>> M)
    {
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        solve(dp, M, row, col);
        return ans;
    }
};
