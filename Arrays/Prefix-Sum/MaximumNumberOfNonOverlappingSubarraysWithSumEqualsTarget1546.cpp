// Given an array nums and an integer target.
// Return the maximum number of non-empty non-overlapping subarrays such that the sum of values in 
// each subarray is equal to target.

// Example 1:
// Input: nums = [1,1,1,1,1], target = 2
// Output: 2
// Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).
// Example 2:
// Input: nums = [-1,3,5,1,4,2,-9], target = 6
// Output: 2
// Explanation: There are 3 subarrays with sum equal to 6.
// ([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
// Example 3:
// Input: nums = [-2,6,6,3,5,4,1,2,8], target = 10
// Output: 3
// Example 4:
// Input: nums = [0,0,0], target = 0
// Output: 3
 
// Constraints:
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// 0 <= target <= 10^6

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        /*
        array : -1,3,5,1,4,2,-9 && target : 6        
        prefix sum: -1,2,7,8,12,14,5        
        */
        unordered_map<int, int> m;
        m[0] = 0;
        int sum = 0, count = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(m.find(sum - target) != m.end()){
                count = max(count, m[sum - target] + 1);
            }
            m[sum] = count;
        }
        return count;
    }
};
