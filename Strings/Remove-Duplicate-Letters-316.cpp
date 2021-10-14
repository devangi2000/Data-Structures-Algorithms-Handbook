// Given a string s, remove duplicate letters so that every letter appears once
// and only once. You must make sure your result is the smallest in 
// lexicographical order among all possible results. 

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> chars(256, 0);
        vector<bool> visited(256, false);
        for(auto a : s)
            chars[a]++;
        string ans = "0";
        for(auto a : s){
            chars[a]--;
            if(visited[a]) continue;
            while(a < ans.back() and chars[ans.back()]){                
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans += a;
            visited[a] = true;
        }
        return ans.substr(1);
    }
};

// or 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0), visited(26, 0);
        for(auto c : s)
            ++count[c-'a'];
        string ans = "";
        for(auto c : s){
            if(visited[c-'a']){
                count[c-'a']--;
                continue;
            }
            while(ans.length() > 0 and ans.back() > c and count[ans.back() - 'a'] > 0){
                visited[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(c);
            count[c-'a']--;
            visited[c-'a'] = 1;
        }
        return ans;
    }
};
