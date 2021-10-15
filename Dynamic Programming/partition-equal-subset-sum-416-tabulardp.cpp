// Given a non-empty array nums containing only positive integers, find if the array can be partitioned
// into two subsets such that the sum of elements in both subsets is equal.

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

class Solution {
public:
      
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);        
        if(sum&1) return false;
        int n = nums.size();
        
        bool dp[n+1][sum/2 + 1];
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=sum/2; ++j){
                if(i==0 || j==0) // Base case
                    dp[i][j] = false;
                else if(nums[i-1] > j) // Skip case
                    dp[i][j] = dp[i-1][j];
                else if(nums[i-1]== j)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum/2];
    }
};
