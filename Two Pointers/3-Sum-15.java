// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets. 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105


class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++){
            int left = i + 1, right = nums.length - 1, target = -nums[i];
            while(left < right){
                if(target == nums[left] + nums[right]){
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[left]);
                    temp.add(nums[i]);
                    temp.add(nums[right]);
                    while(left < right && nums[left] == temp.get(0)) left++;
                    while(left < right && nums[right] == temp.get(2)) right--;
                    ans.add(temp);
                }
                else if(nums[left] + nums[right] < target)
                    left++;
                else right--;
            }
            while(i < nums.length - 1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
}