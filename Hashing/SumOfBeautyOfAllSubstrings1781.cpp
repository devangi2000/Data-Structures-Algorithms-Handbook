// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

 

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
// Example 2:

// Input: s = "aabcbaa"
// Output: 17
 

// Constraints:

// 1 <= s.length <= 500
// s consists of only lowercase English letters.

class Solution {
public:
    int beautySum(string s) {
    int res = 0;
    for (auto i = 0; i < s.size(); ++i) {
        int cnt[26] = {}, max_f = 0, min_f = 0;
        for (auto j = i; j < s.size(); ++j) {
            int idx = s[j] - 'a';
            max_f = max(max_f, ++cnt[idx]);
            if (min_f >= cnt[idx] - 1) {
                min_f = cnt[idx];
                for (int k = 0; k < 26; ++k)
                    min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
            }
            res += max_f - min_f;
        }
    }
    return res;
}
};


