// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

// Given two strings. The task is to find the length of the longest common substring.

// Example 1:

// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.
// Example 2:

// Input: S1 = "ABC", S2 "ACB"
// Output: 1
// Explanation: The longest common substrings
// are "A", "B", "C" all having length 1.
  
// Expected Time Complexity: O(n*m).
// Expected Auxiliary Space: O(n*m).
  

// METHOD 1
  
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 || j==0) dp[i][j] = 0;
                else if(word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m+n-(2*(dp[n][m]));
    }
};


// METHOD 2

class Solution {
   public:    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <= m; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
};
