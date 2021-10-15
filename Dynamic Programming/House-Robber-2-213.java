// You are a professional robber planning to rob houses along a street. Each house has a certain amount
//  of money stashed. All houses at this place are arranged in a circle. That means the first house is 
// the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will
//  automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum 
// amount of money you can rob tonight without alerting the police.

// Example 1:
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        // don't include 0
        int premax1 = 0, curmax1 = 0;
        for(int i = 1; i < n; i++){
            int t = curmax1;
            curmax1 = Math.max(curmax1, nums[i] + premax1);
            premax1 = t;
        }
        
        // don't include n-1
        int premax2 = 0, curmax2 = 0;
        for(int i = 0; i < n-1; i++){
            int t = curmax2;
            curmax2 = Math.max(curmax2, nums[i] + premax2);
            premax2 = t;
        }
        
        return Math.max(curmax1, curmax2);
    }
}