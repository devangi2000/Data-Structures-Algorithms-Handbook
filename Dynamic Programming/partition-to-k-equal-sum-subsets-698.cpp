// Given an integer array nums and an integer k, return true if it is possible to divide this
// array into k non-empty subsets whose sums are all equal.

// Example 1:

// Input: nums = [4,3,2,3,5,2,1], k = 4
// Output: true
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
// Example 2:

// Input: nums = [1,2,3,4], k = 3
// Output: false 

// Constraints:

// 1 <= k <= nums.length <= 16
// 1 <= nums[i] <= 104
// The frequency of each element is in the range [1, 4].

class Solution {
public:
    bool canPartition(int iterationStart, vector<int> &nums, vector<bool> &used, int k, int inProgressBucketSum, int targetBucketSum){
        if(k==1) // 1 bucket left
            return true;
        if(inProgressBucketSum == targetBucketSum)
            return canPartition(0, nums, used, k-1, 0, targetBucketSum);
        for(int i=iterationStart; i<nums.size(); ++i){
            if(!used[i]){
                used[i] = true; // choose
                if(canPartition(i, nums, used, k, inProgressBucketSum+nums[i], targetBucketSum))
                    return true;
                used[i] = false; // don't choose
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(), 0);
        if(sum%k || k==0)
            return false;
        int n = nums.size();
        sum /= k;
        vector<bool>used(n, false);
        return canPartition(0, nums, used, k, 0, sum);
    }
};
