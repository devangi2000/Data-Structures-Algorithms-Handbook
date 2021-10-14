// Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.

// Haven't used Heap here
class Solution {
public:
    static bool cmp(pair<string,int> s, pair<string,int>t)
    {
        if(s.second==t.second) return s.first<t.first;
        return s.second>t.second;
    }
    vector<string> topKFrequent(vector<string>&words, int k) {
        map<string, int> m;
        for(auto a:words)m[a]++;
        vector<pair<string,int>> v;
        for(auto a:m)v.push_back({a.first,a.second});
        sort(v.begin(),v.end(),cmp);
        vector<string> ans;
        for(int i=0; i<k; i++)ans.push_back(v[i].first);
        return ans;
    }
};
