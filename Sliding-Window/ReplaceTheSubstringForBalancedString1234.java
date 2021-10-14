// You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.
// A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.
// Return the minimum length of the substring that can be replaced with any other string of the same length to
//  make the original string s balanced.
// Return 0 if the string is already balanced.

// Example 1:
// Input: s = "QWER"
// Output: 0
// Explanation: s is already balanced.
// Example 2:
// Input: s = "QQWE"
// Output: 1
// Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
// Example 3:
// Input: s = "QQQW"
// Output: 2
// Explanation: We can replace the first "QQ" to "ER". 
// Example 4:
// Input: s = "QQQQ"
// Output: 3
// Explanation: We can replace the last 3 'Q' to make s = "QWER".

// Constraints:
// 1 <= s.length <= 10^5
// s.length is a multiple of 4
// s contains only 'Q', 'W', 'E' and 'R'.

class Solution {
    public int balancedString(String s) {
        int n = s.length(), k = n/4, left = 0, right = 0, count = n;
        Map<Character, Integer> mp = new HashMap<>();
        mp.put('Q', 0); mp.put('W', 0); mp.put('E', 0); mp.put('R', 0);
        for(char c : s.toCharArray())
            mp.put(c, mp.getOrDefault(0, mp.get(c)) + 1);
        for(; right < n; right++){
            mp.put(s.charAt(right), mp.get(s.charAt(right)) - 1);
            while(left < n && mp.get('Q') <= k && mp.get('W') <= k && mp.get('E') <= k && mp.get('R') <= k){
                count = Math.min(count, right - left + 1);
                mp.put(s.charAt(left), mp.get(s.charAt(left)) + 1);
                left++;
            }
        }
        return count;
    }
}