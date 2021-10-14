// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 
// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters

class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        map<char, int> m;
        priority_queue<pair<int, char>> pq;
        for(auto c : s) m[c]++;
        for(auto it : m)
            pq.push({it.second, it.first});
        while(pq.size() > 1){
            auto curr = pq.top();
            pq.pop();
            auto nxt = pq.top();
            pq.pop();
            res += curr.second;
            res += nxt.second;
            curr.first -= 1;
            nxt.first -= 1;
            if(curr.first > 0) pq.push(curr);
            if(nxt.first > 0) pq.push(nxt);
        }  
        if(pq.size() > 0){
            auto curr = pq.top();
            pq.pop();
            if(curr.first > 1) return "";
            res += curr.second;
        }
        return res;
    }
};

