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

public class Solution {    
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int n = s.length(), left = 0, right = 0, maxlen = Integer.MIN_VALUE, count = 0;
        if(n == 0 || k == 0) return 0;
        int[] mp = new int[256];
        while(right < n){
            if(mp[s.charAt(right)] == 0) ++count;
            mp[s.charAt(right)]++;
            right++;
            while(count > k){
                mp[s.charAt(left)]--;
                if(mp[s.charAt(left)]== 0)
                    --count;
                left++;
            }
            maxlen = Math.max(maxlen, right - left);
        }

        return maxlen;
    }
}