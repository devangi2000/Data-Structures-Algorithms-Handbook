// Given a collection of numbers, nums, that might contain duplicates,
// return all possible unique permutations in any order.
// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10


class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void backtrack(int[] nums, List<Integer> temp, int[] freq){
        if(temp.size() == nums.length){
            ans.add(new ArrayList(temp));
            return;
        }
        for(int i = 0; i < nums.length; i++){
            if(freq[i] != 0 || (i > 0 && nums[i] == nums[i-1] && freq[i-1] != 0)) continue;
            freq[i] = 1;
            temp.add(nums[i]);
            backtrack(nums, temp, freq);
            temp.remove(temp.size() - 1);
            freq[i] = 0;
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums){
        Arrays.sort(nums);
        int[] freq = new int[nums.length];
        Arrays.fill(freq, 0);
        backtrack(nums, new ArrayList<>(), freq);
        return ans;
    }
}