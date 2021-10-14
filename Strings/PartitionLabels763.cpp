// You are given a string s. We want to partition the string into as many parts as possible so that each 
// letter appears in at most one part.
// Return a list of integers representing the size of these parts. 

// Example 1:
// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
// Example 2:
// Input: s = "eccbbbbdec"
// Output: [10]

// Constraints:
// 1 <= s.length <= 500
// s consists of lowercase English letters.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size() == 0) return {};
        vector<int> ans, temp(26, 0);
        for(int i = 0; i < s.size(); ++i){
            temp[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            end = max(end, temp[s[i] - 'a']);
            if(i == end){
                ans.push_back(end-start+1);
                start = end + 1;
            }                
        }
        return ans;
    }
};