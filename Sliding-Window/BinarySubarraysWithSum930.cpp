// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// A subarray is a contiguous part of the array.

// Example 1:
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:
// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15 

// Constraints:
// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0, sum = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(m.find(sum - goal) != m.end())
                count += m[sum - goal];
            if(sum == goal) count++;
            m[sum]++;
        }
        return count;
    }
};
