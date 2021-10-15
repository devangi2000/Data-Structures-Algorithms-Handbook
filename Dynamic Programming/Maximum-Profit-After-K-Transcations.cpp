// In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] and a positive integer K, find out the maximum profit a person can make in at-most K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

// Example 1:

// Input: K = 2, N = 6
// A = {10, 22, 5, 75, 65, 80}
// Output: 87
// Explaination: 
// 1st transaction: buy at 10 and sell at 22. 
// 2nd transaction : buy at 5 and sell at 80.
// Example 2:

// Input: K = 3, N = 4
// A = {20, 580, 420, 900}
// Output: 1040
// Explaination: The trader can make at most 2 
// transactions and giving him a profit of 1040.
// Example 3:

// Input: K = 1, N = 5
// A = {100, 90, 80, 50, 25}
// Output: 0
// Explaination: Selling price is decreasing 
// daily. So seller cannot have profit.
// Expected Time Complexity: O(N*K)
// Expected Auxiliary Space: O(N*K)

// Constraints:
// 1 ≤ N ≤ 500
// 1 ≤ K ≤ 200
// 1 ≤ A[ i ] ≤ 1000

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        int maxprofit[K];
        int minprice[K];
        for(int i = 0; i < K; i++){
            minprice[i] = INT_MAX;
            maxprofit[i] = 0;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<K; j++){
                minprice[j] = min(minprice[j], A[i] - ( j>0 ? maxprofit[j-1] : 0));
                maxprofit[j] = max(maxprofit[j], A[i] - minprice[j]);
            }
        }
        return maxprofit[K-1];
    }
};
