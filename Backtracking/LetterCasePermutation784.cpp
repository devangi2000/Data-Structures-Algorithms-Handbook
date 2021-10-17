// Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. You can return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]
// Example 3:

// Input: s = "12345"
// Output: ["12345"]
// Example 4:

// Input: s = "0"
// Output: ["0"]
 

// Constraints:

// s will be a string with length between 1 and 12.
// s will consist only of letters or digits.

// Method 1

class Solution {
public:
    vector<string> ans;    
    void backtrack(string s, int i){
        if(s.size() == i){
            ans.push_back(s);
            return;
        }
        backtrack(s, i+1);
        if(isalpha(s[i])){
            s[i] ^= 1 << 5; // toggle case
            backtrack(s, i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return ans;
    }
};


// Method 2

