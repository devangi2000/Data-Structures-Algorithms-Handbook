// Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

// Recall that a subsequence of an array nums is a list nums[i1], nums[i2], ..., nums[ik] with 0 <= i1 < i2 < ... < ik <= nums.length - 1, and that a sequence seq is arithmetic if seq[i+1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

 

// Example 1:

// Input: nums = [3,6,9,12]
// Output: 4
// Explanation: 
// The whole array is an arithmetic sequence with steps of length = 3.
// Example 2:

// Input: nums = [9,4,7,2,10]
// Output: 3
// Explanation: 
// The longest arithmetic subsequence is [4,7,10].
// Example 3:

// Input: nums = [20,1,15,3,10,5,8]
// Output: 4
// Explanation: 
// The longest arithmetic subsequence is [20,15,10,5].
 

// Constraints:

// 2 <= nums.length <= 1000
// 0 <= nums[i] <= 500


class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 2, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int d = nums[j] - nums[i] + 1000;
                dp[j][d] = max(2, dp[i][d] + 1);
                res = max(res, dp[j][d]);
            }
        }
        return res;
    }
};