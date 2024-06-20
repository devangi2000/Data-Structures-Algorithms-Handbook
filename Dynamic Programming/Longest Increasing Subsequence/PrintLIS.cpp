public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        int lastIndex = 0, ans = 1;
        for(int ind = 0; ind <= n-1 ; ind++){
            hash[ind] = ind;
            for(int prev = 0; prev <= ind-1 ; prev++){
                if(arr[ind] > arr[prev] && dp[ind] < 1 + dp[prev]){
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind] > ans) {
                ans = dp[ind];
                lastIndex = ind;
            }
        }
        vector<int> res;
        res.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            res.push_back(arr[lastIndex]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
