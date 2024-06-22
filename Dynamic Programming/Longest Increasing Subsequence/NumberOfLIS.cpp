class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, c = 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                } else if(nums[i] > nums[j] && dp[i] == 1 + dp[j])
                    count[i] += count[j];
            }
            ans = max(ans, dp[i]);
        }

        for(int i = 0; i < n; i++){
            if(dp[i] == ans)
                c += count[i];
        }

        return c;
    }
};
