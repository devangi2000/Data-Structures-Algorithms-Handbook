// Given a set of N items, each with a weight and a value, and a weight limit W.
// Find the maximum value of a collection containing any of the N items any number of times so that the total weight is less than or equal to W.

// Example 1:

// Input: N = 2, W = 3
// val[] = {1, 1}
// wt[] = {2, 1}
// Output: 3
// Explaination: Pick the 2nd element thrice.
 

// Example 2:

// Input: N = 4, W = 8
// val[] = {1, 4, 5, 7}
// wt[] = {1, 3, 4, 5}
// Output: 11
// Explaination: The optimal choice is to 
// pick the 2nd and 4th element.

// Recursive and gives TLE lol
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        if(N==0 || W==0)
            return 0;

        if(wt[N-1] <= W)
            return max(val[N-1] + knapSack(N, W-wt[N-1], val, wt), knapSack(N-1, W, val, wt));

        return knapSack(N-1, W, val, wt);
    }
};

// Top-Down DP
class Solution{
public:
    int dp[1001][1001];
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1, vector<int>(W+1));
        for(int i=0; i<=N; i++){
            for(int j=0; j<=W; j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
        }
        return dp[N][W];
    }
};

// Recursive + Memoization
class Solution{
public:
    int dp[1001][1001];
    int solve(int N, int W, int val[], int wt[]){
        if(N==0 || W==0) return 0;
        if(dp[N][W] != -1) return dp[N][W];
        if(W < wt[N-1]) return dp[N][W] = solve(N-1, W, val, wt);
        else return dp[N][W] = max(solve(N-1, W, val, wt), val[N-1] + solve(N, W-wt[N-1], val, wt));
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        return solve(N, W, val, wt);
    }
};
