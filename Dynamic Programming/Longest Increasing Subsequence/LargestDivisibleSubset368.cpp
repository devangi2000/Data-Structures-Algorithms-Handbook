// Given a set of distinct positive integers nums, return the largest subset answer such that every pair 
// (answer[i], answer[j]) of elements in this subset satisfies:
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
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 0, lastIndex = -1;
        vector<int> ans;
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        for(int i = 0; i < n; i++){
            if(dp[i] == maxi){
                lastIndex = i;
            }
        }
        ans.push_back(nums[lastIndex]);

        while(lastIndex != hash[lastIndex]) {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
