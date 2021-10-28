// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

class Solution {
    public boolean isValid(String s) {
        if(s.length() < 2 || s.length() % 2 != 0) return false;
        Stack<Character> st = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') st.push(s.charAt(i));
            else if(!st.isEmpty() && st.peek() == '(' && s.charAt(i) == ')') st.pop();
            else if(!st.isEmpty() && st.peek() == '[' && s.charAt(i) == ']') st.pop();
            else if(!st.isEmpty() && st.peek() == '{' && s.charAt(i) == '}') st.pop();
            else return false;
        }
        return st.isEmpty();
    }
}