// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 
// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

// Backtracking Method
class Solution {
     public void backtrack(int[] nums, List<Integer> temp, int start, List<List<Integer>> ans){
        ans.add(new ArrayList<> (temp));
        for(int i = start; i < nums.length; i++){
            temp.add(nums[i]);
            backtrack(nums, temp, i+1, ans);
            temp.remove(temp.size() - 1);
        }
        return;
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(nums, new ArrayList<>(), 0, ans);
        return ans;
    }
}


// Iterative Method and faster

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
    Arrays.sort(nums); // make sure subsets are ordered
    List<List<Integer>> result = new ArrayList<>();
    result.add(new ArrayList<>()); // start with empty set
    for (int i = 0; i < nums.length; ++i) {
        for (int j = 0, size = result.size(); j < size; ++j) { // remember
            List<Integer> subset = new ArrayList<>(result.get(j)); // copy a new one
            subset.add(nums[i]); // expand
            result.add(subset); // collect
        }
    }
    return result;
 }
}