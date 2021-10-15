// https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

// Example:
// Input
// 3
// 8
// 20
// 13
// Output
// 1
// 4
// 2
// Explanation
// For 1st example when n = 8
// { 3, 5 } and {5, 3} are the 
// two possible permutations but 
// these represent the same 
// cobmination. Hence output is 1.

// Constraints:
// 1 ≤ T ≤ 100
// 1 ≤ n ≤ 1000

long long int count(long long int n)
{
    long long int arr[] = {3, 5, 10};
	long long int dp[4][n+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < 4; i++)
	    dp[i][0] = 1;
	for(int i = 1; i < 4; i++){
	    for(int j = 1; j <= n; j++){
	        if(j < arr[i-1])
	            dp[i][j] = dp[i-1][j];
	        else
	            dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
	    }
	}
	return dp[3][n];
}
