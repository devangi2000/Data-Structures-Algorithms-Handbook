// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Example 4:

// Input: s = "aab", p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
// Example 5:

// Input: s = "mississippi", p = "mis*is*p*."
// Output: false

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if(n == 0 or m == 0) return 0;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        dp[0][0] = 1; // base case with both empty strings
        
        for(int i = 1; i <= m; i ++){
            if(i > 1 and p[i-1] == '*' and dp[0][i-2])
                dp[0][i] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j-1] != '*')
                    dp[i][j] = dp[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == '.');
                else
                    dp[i][j] = dp[i][j-2] or (s[i-1] == p[j-2] or p[j-2] == '.') and dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};


        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
   
