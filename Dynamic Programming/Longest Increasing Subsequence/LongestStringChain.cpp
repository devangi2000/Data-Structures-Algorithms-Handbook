class Solution {
public:
    int util(string &word1, string &word2) {
        int len1 = word1.size(), len2 = word2.size(), first = 0, second = 0;
        if (len1 + 1 != len2 ) return false;

        while(second < len2) {
            if(first < len1 && word1[first] == word2[second]){
                first++;
                second++;
            } else second++;            
        }
        if(first == len1 && second == len2) return true;
        return false;
    }

    static bool cmp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans = 1;
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), cmp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(util(words[j], words[i]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
