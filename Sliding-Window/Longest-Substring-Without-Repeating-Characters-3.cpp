// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// Example 4:

// Input: s = ""
// Output: 0

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0, left = 0, right = 0, n = s.size();
        if(n <= 1) return n;
        unordered_map<char, int> m;
        while(right < n){
            m[s[right]]++;
            while(m[s[right]] > 1){
                m[s[left++]]--;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }        
        return maxi;
    }
};

// Enhanced Sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxi = 0, n = s.size();
        for(int i = 0, j = 0; i < n; i++){
            if(m.find(s[i]) != m.end())
                j = max(j, 1 + m[s[i]]);
            m[s[i]] = i;
            maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};
