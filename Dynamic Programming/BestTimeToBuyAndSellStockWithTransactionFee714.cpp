// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.


class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int bsp = -arr[0], ssp = 0; // bsp = bought-state-profit & ssp = sold-state profit
        for(int i = 1; i < arr.size(); ++i){
            int nbsp = 0, nssp = 0; // nbsp = new bought-state-profit & nssp = new sold-state profit
            if(ssp - arr[i] > bsp)
                nbsp = ssp - arr[i];
            else nbsp = bsp;
            
            if(bsp + arr[i] - fee > ssp)
                nssp = bsp + arr[i] - fee;
            else nssp = ssp;
            
            bsp = nbsp;
            ssp = nssp;
        }
        return ssp;
    }
};

// OR

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0], cash = 0;
        for(int i = 1; i < prices.size(); i++){
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};