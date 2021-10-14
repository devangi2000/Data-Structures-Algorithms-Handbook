// Given n pairs of parentheses, write a function to generate 
// all combinations of well-formed parentheses. 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"] 

// Constraints:

// 1 <= n <= 8

class Solution {
public:    
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        backtrack(output, "", 0, 0, n);
        return output;
    }
    
    void backtrack(vector<string> &output, string s, int open, int close, int pairs){
        if(s.size() == pairs*2){
            output.push_back(s);
            return;
        }
        if(open < pairs) backtrack(output, s + "(", open+1, close, pairs);
        if(close < open) backtrack(output, s + ")", open, close+1, pairs);
    }
};
