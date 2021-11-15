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
    public int beautySum(String s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++){
            int[] count = new int[26];
            int maxi = 0, mini = 0;
            for(int j = i; j < n; j++){
                int idx = s.charAt(j) - 'a';
                maxi = Math.max(maxi, ++count[idx]);
                if(mini >= count[idx] - 1){
                    mini = count[idx];
                    for(int k = 0; k < 26; k++)
                        mini = Math.min(mini, count[k] == 0 ? Integer.MAX_VALUE : count[k]);
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
}