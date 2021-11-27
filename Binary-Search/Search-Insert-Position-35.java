// Given a sorted array of distinct integers and a target value, return the index
// if the target is found. If not, return the index where it would be if
//   it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity. 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4
// Example 4:

// Input: nums = [1,3,5,6], target = 0
// Output: 0
// Example 5:

// Input: nums = [1], target = 0
// Output: 0

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

class Solution {
    public int searchInsert(int[] nums, int target) {
        if(target < nums[0]) return 0;
        if(target > nums[nums.length - 1]) return nums.length;
        int low = 0, high = nums.length - 1, ans = -1, last = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            else if(nums[mid] < target){
                low = mid + 1;
                last = mid;
            }
            else high = mid - 1;
        }
        return ans == -1 ? last + 1 : ans;
    }
}
