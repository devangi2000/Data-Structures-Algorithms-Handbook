// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it 
// represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins.
// If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely. 

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:
// Input: nums = [1,5]
// Output: 10
 
// Constraints:

// n == nums.length
// 1 <= n <= 500
// 0 <= nums[i] <= 100

class Solution {
public:
    int dp[502][502];
    int solve(vector<int>& a, int i, int j){
        if(i>=j-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for(int k=i+1; k<j; k++){
            res = max(res, solve(a, i, k) + solve(a, k, j) + a[i]*a[k]*a[j]);
        }
        return dp[i][j] = res;
    }
    int maxCoins(vector<int>& a) {
        a.insert(a.begin(), 1);
        a.insert(a.end(), 1);
        int n = a.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(a, 0, n-1);
        return ans;
    }
};
