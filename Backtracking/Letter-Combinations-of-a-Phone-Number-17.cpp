// Given a string containing digits from 2-9 inclusive, return all possible letter
// combinations that the number could represent. Return the answer in any order.
// A mapping of digit to letters (just like on the telephone buttons) is
// given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

class Solution {
public:
    void backtrack(vector<string> &ans, const vector<string> &pad, const string &digits, string s, int start){
        if(start == digits.size()){
            ans.push_back(s);
            return;
        }
        string letters = pad[digits[start] - '0'];
        for(int i=0; i<letters.size(); ++i){
            backtrack(ans, pad, digits, s+letters[i], start+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        const vector<string> pad = {"", "", "abc", "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(ans, pad, digits, "", 0);
        return ans;
    }
};
