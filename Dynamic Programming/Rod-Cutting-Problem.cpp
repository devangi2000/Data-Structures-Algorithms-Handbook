// Given a rod of length N inches and an array of prices that contains prices of all pieces of size smaller than N.
// Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Example 1:
// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.
// Example 2:

// Input:
// N=8
// Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
// Output: 24
// Explanation: 
// The maximum obtainable value is 
// 24 by cutting the rod into 8 pieces 
// of length 1, i.e, 8*3=24. 
// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N)


class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        vector<int> v;
        for(int i=1;i<=n; i++) v.push_back(i);
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=n; ++j){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(v[i-1] <= j) dp[i][j] = max(price[i-1] + dp[i][j-v[i-1]],dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};
