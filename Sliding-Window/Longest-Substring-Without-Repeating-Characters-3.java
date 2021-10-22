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
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), maxi = 0;
        Map<Character, Integer> mp = new HashMap<>();
        for(int i = 0, j = 0; i < n; i++){
            if(mp.containsKey(s.charAt(i)))
                j = Math.max(j, mp.get(s.charAt(i)) + 1);
            mp.put(s.charAt(i), i);
            maxi = Math.max(maxi, i - j + 1);
        }
        return maxi;
    }
}