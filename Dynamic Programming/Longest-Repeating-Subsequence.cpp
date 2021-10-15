// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

// Given a string, find the length of the longest repeating subsequence such that the two subsequences don't
// have same string character at the same position, i.e., any i'th character in the two subsequences shouldn't have the same index in the original string.

// Example 1:

// Input: str = "axxxy"
// Output: 2
// Explanation: The longest repeating subsequenece
// is "xx".
// Example 2:

// Input: str = "aab"
// output: 1
// Explanation: The longest reapting subsequenece
// is "a".
// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)

// Same as LCS with only one change: i != j
class Solution{
public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
		    for(int i=1; i<=n; i++){
		        for(int j=1; j<=n; j++){
		            if(str[i-1] == str[j-1] and i!=j)
		                dp[i][j] = 1 + dp[i-1][j-1];
		            else
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		        }
		    }
		    return dp[n][n];
		}

};
