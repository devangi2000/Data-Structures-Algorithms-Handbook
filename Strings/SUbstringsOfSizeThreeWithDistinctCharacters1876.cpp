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
public:
    int countGoodSubstrings(string s) {
        int n = s.size(), count = 0;
        if(n < 3) return 0;
        for(int i = 0; i < n-2; i++){
            char a = s[i], b = s[i+1], c = s[i+2];
            if((a == b) || (a == c) || (b == c)) continue;
            ++count;
        }
        return count;
    }
};

// OR

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size(), count = 0, start = 0, end = 0;
        if(n < 3) return 0;
        unordered_map<char, int> m;
        while(end < n){
            m[s[end]]++;
            if(end - start + 1 < 3) end++;
            else if(end - start + 1 == 3){
                if(m.size() == 3) ++count;
                if((--m[s[start]]) == 0)
                    m.erase(s[start]);
                start++;
                end++;
            }
        }
        return count;
    }
};

