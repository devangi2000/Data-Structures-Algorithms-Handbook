// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.
// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1

class Solution {
public:
    int subsetSum(vector<int> &nums, int s1){
        int n = nums.size();
        int dp[n+1][s1+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=s1; j++){
                if(i==0 and j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else if(j>=nums[i-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]]; 
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s1];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto a:nums) sum+=a;
        if(target>sum || target< -1*sum) return 0;
        int s1 = (target+sum)/2, n = nums.size();         
        if((target+sum)%2) return 0;
        return subsetSum(nums, s1);
    }
};

