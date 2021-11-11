// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

class Solution {
    public String longestPalindrome(String s) {
        boolean[][] dp = new boolean[s.length()][s.length()];
        String res = "";
        for(int g = 0; g < s.length(); g++){
            for(int i = 0, j = g; j < s.length(); i++, j++){
                if(g == 0)
                    dp[i][j] = true;
                else if(g == 1)
                    dp[i][j] = s.charAt(i) == s.charAt(j);
                else{
                    dp[i][j] = ((s.charAt(i) == s.charAt(j)) && dp[i+1][j-1] == true);
                }
                if(dp[i][j] == true && res.length() < (j-i+1))
                    res = s.substring(i, j+1);
            }
        }
        return res;
    }
}