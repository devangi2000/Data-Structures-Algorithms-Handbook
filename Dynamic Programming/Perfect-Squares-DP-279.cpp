// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words,
// it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
  
class Solution {
public:
    int numSquares(int n) {
        int vals = sqrt(n);
        vector<vector<int>> dp((vals+1), vector<int> (n+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            dp[0][i] = INT_MAX-1;
        }        
        for(int i=1; i<=vals; i++){
            for(int j=1; j<=n; j++){
                if((i*i)<= j) dp[i][j] = min(1 + dp[i][j-(i*i)], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[vals][n];
    }
};
