// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 
// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.


// METHOD 1
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto a: wordDict)
            words.insert(a);
        if(wordDict.size() == 0) return false;
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i=0; i<=n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    string temp = s.substr(j, i-j);
                    if(words.find(temp)!=words.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};        


// METHOD 2
class Solution {
public:
    unordered_map<string, int> m;
    int canBreak(string s, vector<string> &wordDict){
        int sz = s.size();
        if(sz == 0) return 1;
        if(m[s] != 0) return m[s];
        for(int i=1; i<=sz; i++){
            int flag = 0;
            string temp = s.substr(0,i);
            for(int j=0; j<wordDict.size(); j++){
                if(temp.compare(wordDict[j]) == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag==1 and canBreak(s.substr(i, sz-i), wordDict)==1) return m[s] = 1;
        }
        return m[s] = -1;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       // vector<vector<bool>> (s.size()+1, vector<bool> (s.size() + 1));
        int x = canBreak(s, wordDict);
        if(x==1) return true;
        return false;
    }
};
