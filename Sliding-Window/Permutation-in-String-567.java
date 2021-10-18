// Given two strings s1 and s2, return true if s2 contains the permutation of s1.
// In other words, one of s1's permutations is the substring of s2.

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.
// Method 1
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int p = s1.length(), n = s2.length();
        if(p > n) return false;
        int[] m1 = new int[26];
        for(Character c : s1.toCharArray())
            m1[c - 'a']++;
        for(int i = 0; i <= n - p; i++){
            int[] m2 = new int[26];
            for(int j = 0; j < p; j++){
                m2[s2.charAt(i+j) - 'a']++;
            }
            if(matches(m1, m2) == true) return true;
        }
        return false;
    }
    
    public boolean matches(int[] m1, int[] m2){
        for(int i = 0; i < 26; i++)
            if(m1[i] != m2[i]) return false;
        return true;
    }
}
  
// Sliding Window

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int p = s1.length(), n = s2.length();
        if(p > n) return false;
        int[] m1 = new int[26];
        int[] m2 = new int[26];
        for(int i = 0; i < p; i++){
            m1[s1.charAt(i) - 'a']++;
            m2[s2.charAt(i) - 'a']++;
        }
        for(int i = 0; i < n - p; i++){
            if(matches(m1, m2) == true) return true;
            m2[s2.charAt(i+p) - 'a']++;
            m2[s2.charAt(i) - 'a']--;
        }
        return matches(m1, m2);
    }
    
    public boolean matches(int[] m1, int[] m2){
        for(int i = 0; i < 26; i++)
            if(m1[i] != m2[i]) return false;
        return true;
    }
}