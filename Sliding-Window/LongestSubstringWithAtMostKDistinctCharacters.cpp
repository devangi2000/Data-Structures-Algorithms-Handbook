// Given a string S, find the length of the longest substring T that contains at most k distinct characters.
// Example
// Example 1:
// Input: S = "eceba" and k = 3
// Output: 4
// Explanation: T = "eceb"
// Example 2:
// Input: S = "WORLD" and k = 4
// Output: 4
// Explanation: T = "WORL" or "ORLD"
// Challenge
// O(n) time

class Solution {
public:
    
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int maxlen = INT_MIN, left = 0, right = 0, n = s.length();
        if(n == 0 || k == 0) return 0;
        unordered_map<char, int> m;
        while(right < n){
            m[s[right++]]++;
            while(m.size() > k){
                m[s[left]]--;
                if(m[s[left]] == 0)
                    m.erase(s[left]);
                left++;
            }
            maxlen = max(maxlen, right - left);                
        }
        return maxlen;
    }
};
