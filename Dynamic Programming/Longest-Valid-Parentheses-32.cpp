// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring. 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0 

// Constraints:
// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.


class Solution {
public:
    int ans = 0;
    int longestValidParentheses(string s){
       int n = s.size();
        if(n <= 1) return 0;
        vector<int> dp(n, 0);
        int len = 0;
        for(int i = 1; i < n; i++){
            if(s[i-1] == '(' and s[i] == ')'){
                dp[i] = i>=2? dp[i-2] + 2: 2;
                ans = max(ans, dp[i]);
            }
            else
            {
                if(i-dp[i-1] >= 1 and s[i] == ')' and s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0) ? dp[i - dp[i-1] - 2] : 0);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};

