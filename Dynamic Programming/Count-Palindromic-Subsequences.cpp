// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
// Note: You have to return the answer module 109+7; 

// Example 1:

// Input: 
// Str = "abcd"
// Output: 
// 4
// Explanation:
// palindromic subsequence are : "a" ,"b", "c" ,"d" 

// Example 2:

// Input: 
// Str = "aab"
// Output: 
// 4
// Explanation:
// palindromic subsequence are :"a", "a", "b", "aa"

// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N*N)

// Constraints:
// 1<=length of string str <=1000

// Read this https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/272297/DP-C++-Clear-solution-explained


// Gives int overflow on GFG
class Solution{
    public:
    int dp[1001][1001];
    
    long long int solve(int start, int end, string &str){
        if(start > end) return 0;
        if(start ==  end) return 1; // single element
        
        if(dp[start][end] != -1) return dp[start][end]; // memoized
        
        if(str[start] == str[end]) 
            return dp[start][end] = 1 + solve(start+1, end, str) + solve(start,end-1, str);
        
        return dp[start][end] = solve(start+1, end, str) + solve(start, end-1, str) - solve(start+1, end-1, str);
    }
    
    long long int  countPS(string str)
    {
       int n = str.size();
       dp[n][n];
       memset(dp, -1, sizeof(dp));
       return solve(0, n-1, str);
    }
     
};
