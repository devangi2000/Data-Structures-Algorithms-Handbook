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

public class Solution {
    
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int left = 0, right = 0, maxlen = Integer.MIN_VALUE, n = s.length(), count = 0;
        if(n == 0) return 0;
        int[] m = new int[256];
        while(right < n){
            if(m[s.charAt(right)] == 0) count++;
            m[s.charAt(right)]++;
            right++;
            while(count > 2){
                m[s.charAt(left)]--;
                if(m[s.charAt(left)] == 0)
                    count--;
                left++;
            }
            maxlen = Math.max(maxlen, right - left);
        }
        return maxlen;
    }
}