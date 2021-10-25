// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10


class Solution {
    public void backtrack(int[] nums, List<Integer> temp, int start, List<List<Integer>> ans){
        ans.add(new ArrayList<>(temp));
        for(int i = start; i < nums.length; i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            temp.add(nums[i]);
            backtrack(nums, temp, i+1, ans);
            temp.remove(temp.size()-1);
        }
        return;
    }
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(nums, new ArrayList<>(), 0, ans);
        return ans;
    }
}