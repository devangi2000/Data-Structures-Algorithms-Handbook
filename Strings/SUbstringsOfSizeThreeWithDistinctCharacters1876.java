// A string is good if there are no repeated characters.

// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
// The only good substring of length 3 is "xyz".
// Example 2:

// Input: s = "aababcabc"
// Output: 4
// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
// The good substrings are "abc", "bca", "cab", and "abc".
 

// Constraints:

// 1 <= s.length <= 100
// s​​​​​​ consists of lowercase English letters.


class Solution {
    public int countGoodSubstrings(String s) {
        int n = s.length(), count = 0;
        if(n < 3) return 0;
        for(int i = 0; i < n-2; i++){
            char a = s.charAt(i), b = s.charAt(i+1), c = s.charAt(i+2);
            if((a == b) || (a == c) || (b == c)) continue;
            ++count;
        }
        return count;
    }
}


// Method 2

class Solution {
    public int countGoodSubstrings(String s) {
        int n = s.length(), count = 0, start = 0, end = 0;
        Map<Character, Integer> mp = new HashMap<>();
        while(end < n){
            mp.put(s.charAt(end), mp.getOrDefault(s.charAt(end), 0) + 1);
            if(end - start + 1 < 3) end++;
            else if(end - start + 1 == 3){
                if(mp.size() == 3) ++count;
                int val = mp.get(s.charAt(start));
                val -= 1;
                if(val == 0)
                    mp.remove(s.charAt(start));
                else mp.put(s.charAt(start), val);
                end++; start++;
            }
        }
        return count;
    }
}

