// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
// Example 4:

// Input: prices = [1]
// Output: 0
 
// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105


// Method 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price1=INT_MAX, min_price2=INT_MAX, profit1=0, profit2=0;
        for(int i=0;i<prices.size();i++)
        {
            min_price1 = min(prices[i], min_price1);
            profit1=max(profit1, prices[i]-min_price1);
            min_price2 = min(min_price2, prices[i]-profit1);
            profit2 = max(profit2, prices[i]-min_price2);
        }
        return profit2;
    }
};

// Method 2
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<int> dp(n, 0);
        int mx = prices[n-1], mn = prices[0];
        for(int i = n-2; i >= 0; i--){
            mx = max(mx, prices[i]);
            dp[i] = max(dp[i+1], mx - prices[i]);
        }
        for(int i = 1; i < n; i++){
            mn = min(mn, prices[i]);
            dp[i] = max(dp[i-1], dp[i] + (prices[i] - mn));
        }
        return dp[n-1];
    }
};
