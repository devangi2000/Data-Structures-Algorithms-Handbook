// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []
// Example 4:

// Input: candidates = [1], target = 1
// Output: [[1]]
// Example 5:

// Input: candidates = [1], target = 2
// Output: [[1,1]]
 

// Constraints:

// 1 <= candidates.length <= 30
// 1 <= candidates[i] <= 200
// All elements of candidates are distinct.
// 1 <= target <= 500
  // TC: (2^target) * k

class Solution {
    public void backtrack(int[] nums, List<Integer> temp, List<List<Integer>> ans, int start, int target){
        if(target == 0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        if(start == nums.length || target < 0)
            return;
        temp.add(nums[start]);
        backtrack(nums, temp, ans, start, target - nums[start]);
        temp.remove(temp.size() - 1);
        backtrack(nums, temp, ans, start + 1, target);
    }
    
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(nums, new ArrayList<>(), ans, 0, target);
        return ans;
    }
}