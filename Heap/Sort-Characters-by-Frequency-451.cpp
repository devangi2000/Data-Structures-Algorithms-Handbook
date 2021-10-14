// Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.
// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// Constraints:
// 1 <= s.length <= 5 * 105
// s consists of English letters and digits.

// APPROACH 1: no comparator and only maxHeap
class Solution {
public:    
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> m;
        priority_queue<pair<int,char>> maxHeap;
        for(auto i:s)
            m[i]++;
        for(auto it=m.begin(); it!=m.end(); it++){
            maxHeap.push({it->second, it->first});
        }
        while(!maxHeap.empty()){
            int n = maxHeap.top().first;
            while(n--) ans+=maxHeap.top().second;
            maxHeap.pop();
        }
        return ans;
    }
};



// APPROACH 2
class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b)
    {
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        vector<pair<char,int>> v;
        for(auto a:m)
        {
            v.push_back({a.first, a.second});
        }
        sort(v.begin(), v.end(), cmp);
        string res="";
        for(int i=0; i<v.size(); i++)
        {while((v[i].second)--)res+=v[i].first;}
        return res;
    }
};
