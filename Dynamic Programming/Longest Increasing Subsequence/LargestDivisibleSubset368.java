// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length, maxlen = 0, maxind = -1;
        int[] dp = new int[n];
        int[] pre = new int[n];
        Arrays.sort(nums);
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            pre[i] = -1;
            for(int j = i-1; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        pre[i] = j;
                    }
                }
            }            
            if(maxlen < dp[i]){
                maxlen = dp[i];
                maxind = i;
            }
        }
        
        List<Integer> res = new ArrayList<>();
        while(maxind != -1){
            res.add(nums[maxind]);
            maxind = pre[maxind];
        }
        
        return res;
    }
}