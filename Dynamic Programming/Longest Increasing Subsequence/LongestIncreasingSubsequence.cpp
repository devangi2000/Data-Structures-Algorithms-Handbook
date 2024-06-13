// Memoization

class Solution {
public:

    int solve(vector<int> &nums, vector<vector<int>> &dp, int n, int ind, int prev){
        if(ind == n) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int notTake = solve(nums, dp, n, ind+1, prev);
        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev])
            take = 1 + solve(nums, dp, n, ind+1, ind);
        return dp[ind][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, dp, n, 0, -1);
    }
};


// Tabulation - 1D

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = INT_MIN;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < 1 + dp[j])
                    dp[i] = 1 + dp[j];
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
