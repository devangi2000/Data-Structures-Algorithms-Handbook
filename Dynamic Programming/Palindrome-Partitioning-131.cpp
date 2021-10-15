// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// A palindrome string is a string that reads the same backward as forward.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string s){
        int i=0, j = s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    void solve(string s, int index, vector<string> &path){
        if(index == s.size()){
            res.push_back(path);
            return;
        }
        for(int i=index; i<s.size(); ++i){
            string temp = s.substr(index, i-index+1);
            if(isPalindrome(temp)){
                path.push_back(temp);
                solve(s, i+1, path);
                path.pop_back(); 
            }           
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s, 0, path);
        return res;
    }
};
