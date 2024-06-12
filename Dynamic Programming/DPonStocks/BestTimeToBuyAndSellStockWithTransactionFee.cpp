// Memoization

class Solution {
public:

    int solve(vector<int> &prices, vector<vector<int>> &dp, int ind, int buy, int fee) {
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy == 0)
            profit = max(solve(prices, dp, ind + 1, 0, fee), 
                    - prices[ind] + solve(prices, dp, ind + 1, 1, fee));
        if(buy == 1)
            profit = max(solve(prices, dp, ind + 1, 1, fee),
                    - fee + prices[ind] + solve(prices, dp, ind + 1, 0, fee));

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int> (2, -1));
        return solve(prices, dp, 0, 0, fee);
    }
};


// Tabulation

class Solution {
public:    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int> (2, 0));
        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 0)
                    dp[i][buy] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
                else if(buy == 1)
                    dp[i][buy] = max(dp[i+1][1], prices[i] - fee + dp[i+1][0]);
            }
        }
        return dp[0][0];
    }
};

