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
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        if(n <= 0) return ans;
        Arrays.sort(nums);
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                int sum = target - nums[i] - nums[j], left = j+1, right = n-1;
                while(left < right){
                    int twoSum = nums[left] + nums[right];
                    if(twoSum == sum){
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[left]);
                        temp.add(nums[right]);
                        ans.add(temp);
                        while(left < right && nums[left] == temp.get(2)) left++;
                        while(left < right && nums[right] == temp.get(3)) right--;
                    }
                    else if(twoSum < sum)
                        left++;
                    else right--;
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
            
        return ans;
    }
}