// Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
// Example
// Example 1
// Input: “eceba”
// Output: 3
// Explanation:
// T is "ece" which its length is 3.
// Example 2
// Input: “aaa”
// Output: 3

class Solution {
public:

    int lengthOfLongestSubstringTwoDistinct(string &s) {
        int left = 0, right = 0, maxlen = INT_MIN, n = s.length();
        if(n == 0) return 0;
        unordered_map<char, int> m;
        while(right < n){
            m[s[right++]]++;
            while(m.size() > 2){
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