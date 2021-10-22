// Given an array nums of n integers and an integer target, find three integers in nums such
// that the sum is closest to target. Return the sum of the three integers. You may assume 
// that each input would have exactly one solution. 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
// Constraints:

// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        int closest = sum;
        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int low = i+1, high = n-1;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];
                if(sum == target){
                    return sum;
                }
                else if(sum < target){
                    while(low < high and nums[low]==nums[low+1]) low++;
                    low++;
                }
                else if(sum > target){
                    while(high > low and nums[high] == nums[high-1]) high--;
                    high--;
                }
               closest = abs(target - sum) > abs(target - closest) ? closest : sum;
            }          
        }
       return closest;
    }
};
