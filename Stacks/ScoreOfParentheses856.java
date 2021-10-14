// Given a balanced parentheses string s, return the score of the string.
// The score of a balanced parentheses string is based on the following rule:
// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.

// Example 1:
// Input: s = "()"
// Output: 1
// Example 2:
// Input: s = "(())"
// Output: 2
// Example 3:
// Input: s = "()()"
// Output: 2
// Example 4:
// Input: s = "(()(()))"
// Output: 6
 
// Constraints:
// 2 <= s.length <= 50
// s consists of only '(' and ')'.
// s is a balanced parentheses string.

class Solution {
    public int scoreOfParentheses(String s) {
        Stack<Integer> st = new Stack();
        st.push(0);
        for(char c : s.toCharArray()){
            if(c == '(')
                st.push(0);
            else{
                int u = st.pop();
                int v = st.pop();
                st.push(v + Math.max(1, 2*u));
            }
        }
        return st.pop();
    }
}