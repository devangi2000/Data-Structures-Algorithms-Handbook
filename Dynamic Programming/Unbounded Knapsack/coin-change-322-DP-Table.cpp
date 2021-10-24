// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
// Example 4:

// Input: coins = [1], amount = 1
// Output: 1
// Example 5:

// Input: coins = [1], amount = 2
// Output: 2

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        int dp[n+1][amount+1];
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=amount; ++j){
                if(j==0) dp[i][j] = 0;
                else if(i==0) dp[i][j] = 1e5;
                else if(coins[i-1]>j) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = min(dp[i-1][j], 1+ dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[n][amount] < 1e4 ? dp[n][amount] : -1;
    }
};
