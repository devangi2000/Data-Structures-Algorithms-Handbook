// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively.
// Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

// Example 1:

// Input:
// N = 3
// W = 4
// values[] = {1,2,3}
// weight[] = {4,5,1}
// Output: 3
// Example 2:

// Input:
// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
// Output: 0

// Recursive, gives TLE
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(W==0 || n==0) return 0;
       else if(W<wt[n-1]) return knapSack(W, wt, val, n-1);
       else return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
    }
};

// Top-Down
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1, vector<int>(W+1));
       for(int i=0; i<=n; i++){
           for(int j=0; j<=W; j++){
               if(i==0 || j==0) dp[i][j] = 0;
               else if(wt[i-1]>j) dp[i][j] = dp[i-1][j];
               else dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
           }
       }
       return dp[n][W];
    }
};

// Recursive-Memoization
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int solve(int W, int wt[], int val[], int n){
        if(W==0 || n==0) return 0;
        if(dp[n][W] != -1) return dp[n][W];
        if(W<wt[n-1]) return dp[n][W] = solve(W, wt, val, n-1);
        else return dp[n][W] = max(solve(W, wt, val, n-1), val[n-1]+solve(W-wt[n-1], wt, val, n-1));
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp, -1, sizeof(dp));
       return solve(W, wt, val, n);
    }
};
