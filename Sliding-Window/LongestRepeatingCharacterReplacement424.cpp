// You are given a string s and an integer k. You can choose any character of the string and change it to any 
// other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the 
// above operations.
// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

// Constraints:
// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, maxi = 0, maxcount = 0, n = s.size();
        unordered_map<char, int> m;
        for(int end = 0; end < n; end++){
            maxcount = max(maxcount, ++m[s[end]]);            
            while(end - start + 1 - maxcount > k){
                m[s[start++]]--;
            }                
            maxi = max(maxi, end - start + 1);
        }
        return maxi;
    }
};
