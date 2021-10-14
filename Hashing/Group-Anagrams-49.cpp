// Given an array of strings strs, group the anagrams together.
// You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters 
// of a different word or phrase, typically using all the original letters exactly once. 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lower-case English letters.

// Approach 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(auto str : strs){
            string s = str;
            sort(str.begin(), str.end());
            m[str].push_back(s);
        }
        for(auto it = m.begin(); it != m.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
};

