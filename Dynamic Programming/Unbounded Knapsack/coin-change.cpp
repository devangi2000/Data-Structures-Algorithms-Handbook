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
        vector<int> dp(amount+1,  INT_MAX-1);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto coin:coins){
                if(i>=coin){
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                } else break;
            }
        }
        return (dp[amount]!= INT_MAX-1)? dp[amount]:-1;
    }
};
