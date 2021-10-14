// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(s.size() != t.size()) return false;
        for(auto a : s) m[a]++;
        for(auto a: t)
        {            
           if(m.find(a) == m.end()){
               return false;
            }
           else if(m.find(a)!=m.end())
            {
                m[a]--;
                if(m[a]<0) return false;
            }   
           else continue;
        }
        return true;
    }
};
