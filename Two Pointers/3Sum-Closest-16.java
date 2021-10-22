// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.


// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        if(n < 3) return 0;
        Arrays.sort(nums);
        int sum = nums[0] + nums[1] + nums[2], closest = sum;
        for(int i = 0; i < n-1; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int left = i + 1, right = n - 1;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;
                else if(sum < target){
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                }
                else{
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    right--;
                }
            closest = Math.abs(target - sum) > Math.abs(target - closest) ? closest : sum;
           }
        }
        return closest;
    }
}