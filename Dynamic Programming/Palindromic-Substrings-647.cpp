// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string. 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<vector<bool>>dp(n, vector<bool>(n));
        for(int gap = 0; gap<n; gap++){
            for(int i=0, j = gap; j < n; i++, j++){
                if(gap == 0) 
                    {dp[i][j] = true;
                    count++; 
                    }
                else if(gap == 1){
                    dp[i][j] = s[i]==s[j];
                    if(dp[i][j]) count++;
                }
                else{
                    dp[i][j] = (dp[i+1][j-1] && (s[i]==s[j]));
                    if(dp[i][j]) count++;
                }                
            }             
        }
        return count;
    }
};
