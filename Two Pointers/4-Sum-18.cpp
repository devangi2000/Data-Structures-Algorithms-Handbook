// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.


// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                int num = target - nums[i] - nums[j], left = j + 1, right = n - 1;
                while(left < right){
                    int sum = nums[left] + nums[right];
                    if(sum == num){
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(temp);
                        while(left < right and nums[left] == temp[2]) left++;
                        while(left < right and nums[right] == temp[3]) right--;
                    }
                    else if(sum < num)
                        left++;
                    else right--;
                }
                while(j + 1 < n and nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n and nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};