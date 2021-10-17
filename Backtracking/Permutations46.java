// Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.
class Solution {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    public void backtrack(int[] nums, List<Integer> temp){
        if(temp.size() == nums.length){
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(temp.contains(nums[i])) continue;
            temp.add(nums[i]);
            backtrack(nums, temp);
            temp.remove(temp.size()-1);
        }
        return;
    }
    
    public List<List<Integer>> permute(int[] nums) {
        backtrack(nums, new ArrayList<Integer>());
        return ans;
    }
}
