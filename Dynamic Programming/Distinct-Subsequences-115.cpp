// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// A string's subsequence is a new string formed from the original string by deleting some (can be none)
// of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a 
// subsequence of "ABCDE" while "AEC" is not).
// It is guaranteed the answer fits on a 32-bit signed integer.

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag
 

// Constraints:

// 1 <= s.length, t.length <= 1000
// s and t consist of English letters.

class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& a, string& b, int m, int n){
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(n <= 0)
            return dp[m][n] = 1;
        
        if(m <= 0)
            return dp[m][n] = 0;
        
        if(a[m - 1] == b[n - 1])
            return dp[m][n] = solve(a, b, m - 1, n - 1) + solve(a, b, m - 1, n);
        
        return dp[m][n] = solve(a, b, m - 1, n);
}
        int numDistinct(string s, string t) {
        dp.clear();
        dp.resize(s.size() + 1, vector<int> (t.size() + 1, -1));
            
        return solve(s, t, s.size(), t.size());
    }
};
