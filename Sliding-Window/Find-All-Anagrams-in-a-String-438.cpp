// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
 
// Constraints:

// 1 <= s.length, p.length <= 3 * 104
// s and p consist of lowercase English letters.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int start = 0, end = 0, n = s.size(), k = p.size(), len = INT_MAX;
        if(n < k) return ans;
        unordered_map<char, int> m;
        for(auto a : p)
            m[a]++;
        int counter = m.size();
        while(end < n){
            char c = s[end];
            if(m.find(c) != m.end()){
                m[c]--;
                if(m[c] == 0)
                    counter--;
            }
            end++;
            while(counter == 0){
                char temp = s[start];
                if(m.find(temp) != m.end()){
                    m[temp]++;
                    if(m[temp]>0)
                        counter++;
                }      
            if(end - start == k)
                ans.push_back(start);
            start++;
           }  
        }
        return ans;
    }
};
