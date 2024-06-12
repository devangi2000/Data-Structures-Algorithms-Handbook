// Memoization

class Solution {
public:

    int solve(vector<int> &prices, vector<vector<int>> &dp, int ind, int buy, int n){
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy == 0) { // can buy
            profit = max(solve(prices, dp, ind + 1, 0, n),
                    -prices[ind] + solve(prices, dp, ind + 1, 1, n));
        }
        if(buy == 1) { // can sell
            profit = max(solve(prices, dp, ind + 1, 1, n), 
                    prices[ind] + solve(prices, dp, ind + 2, 0, n));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, -1));
        return solve(prices, dp, 0, 0, n);
    }
};


// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int i = n-1; i >=0; i--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 0)
                    dp[i][buy] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
                else if(buy == 1)
                    dp[i][buy] = max(dp[i+1][1], prices[i] + dp[i+2][0]);
            }
        }
        return dp[0][0];
    }
};
