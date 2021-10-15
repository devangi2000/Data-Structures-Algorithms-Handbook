// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s. 

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1

// Constraints:

// 1 <= s.length <= 2000
// s consists of lower-case English letters only.

class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    int solve(string &s, int start, int end){
        if(start>=end or isPalindrome(s, start, end)) return dp[start][end]=0;
        if(dp[start][end] != -1) return dp[start][end];
        int mn = INT_MAX;
        for(int i = start; i < end; i++){
            if(isPalindrome(s, start, i))
                mn = min(mn, 1 + solve(s, i+1, end));
        }
        return dp[start][end] = mn;
    }
    
    int minCut(string s){
        int n = s.size();
        dp.resize(n, vector<int> (n, -1));
        return solve(s, 0, s.size()-1);        
    }
}; 
