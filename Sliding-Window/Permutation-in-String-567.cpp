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
public:
    bool checkInclusion(string s1, string s2) {
        int p = s1.size(), n = s2.size();
        if(p > n) return false;
        vector<int> m1(26, 0);
        for(char c : s1)
            m1[c - 'a']++;
        for(int i = 0; i <= n - p; i++){
            vector<int> m2(26, 0);
            for(int j = 0; j < p; j++){
                m2[s2[i+j] - 'a']++;
            }
            if(matches(m1, m2)) return true;
        }
        return false;
    }
    
    bool matches(vector<int> m1, vector<int> m2){
        for(int i = 0; i < 26; i++)
            if(m1[i] != m2[i]) return false;
        return true;
    }
};

// Method 2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int p = s1.size(), n = s2.size(), start = 0, end = 0;
        if(n < p) return false;
        unordered_map<char, int> m;
        for(auto a : s1)
            m[a]++;
        int counter = m.size();
        bool ans = false;
        while(end < n){
            char c = s2[end];
            if(m.find(c) != m.end()){
                m[c]--;
                if(m[c] == 0)
                    counter--;
            }
            end++;
            while(counter == 0){
                char temp = s2[start];
                if(m.find(temp) != m.end()){
                    m[temp]++;
                    if(m[temp]>0)
                        counter++;
                }
                if(end - start == p)
                    return true;
                start++;
            }
        }
        return false;
    }
};
