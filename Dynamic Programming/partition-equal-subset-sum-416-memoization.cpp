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
 
// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

class Solution {
public:
    vector<vector<int>> dp;
    bool subsetSum(vector<int> &nums, int n, int pos, int sum){
        if(sum==0) // sum found
            return true;        
        else if(pos>=n || sum<0) // out of bounds
            return false;
        if(dp[pos][sum] != -1) // already calculated earlier
            return dp[pos][sum];
         // not calculated earlier, so it's the include OR exclude case; we may or may not include it
        return dp[pos][sum] = subsetSum(nums, n, pos+1, sum-nums[pos]) || subsetSum(nums, n, pos+1, sum);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);        
        if(sum&1) return false;
        int n = nums.size();
        dp.clear();
        dp.resize(n+1, vector<int>(sum/2+1, -1));
        return subsetSum(nums, n, 0, sum/2);
    }
};
