// Given a string s, partition s such that every substring of the partition is a palindrome. 
// Return all possible palindrome partitioning of s.
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
        int start = 0, end = s.size() - 1;
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    void solve(string s, int start, vector<string> &temp){
        if(start == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=start; i<s.size(); ++i){
            string str = s.substr(start, i - start + 1);
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(s, i+1, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s){
        vector<string> path;
        solve(s, 0, path);
        return res;
    }
};
