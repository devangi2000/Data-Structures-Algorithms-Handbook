// Given a string containing just the characters '(' and ')', find the 
// length of the longest valid (well-formed) parentheses substring.

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
//  Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

class Solution {
public:
    stack<int> st;
    int ans = 0;
    int longestValidParentheses(string s){
        int n = s.size();
        st.push(-1);
        for(int i=0; i<n; ++i){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                ans = max(ans, i - st.top());
            }
        }
        return ans;   
    }
};
