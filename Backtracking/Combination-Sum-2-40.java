// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30



class Solution {
    public void backtrack(int[] nums, List<Integer> temp, int start, int target, List<List<Integer>> ans){
        if(target == 0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        if(target < 0)
            return;
        for(int i = start; i < nums.length; i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            temp.add(nums[i]);
            backtrack(nums, temp, i+1, target - nums[i], ans);
            temp.remove(temp.size() - 1);
            
        }
    }
    
    public List<List<Integer>> combinationSum2(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        backtrack(nums, new ArrayList<>(), 0, target, ans);
        return ans;
    }
}
