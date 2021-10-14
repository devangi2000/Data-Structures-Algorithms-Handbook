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
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = target - nums[i] - nums[j];
                int low = j + 1, high = n - 1;
                while(low < high){
                    int twoSum = nums[low] + nums[high];
                    if(twoSum < sum)
                        low++;
                    else if(twoSum > sum)
                        high--;
                    else{
                        vector<int> temp(4, 0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        while(low < high and nums[low] == temp[2]) low++;
                        while(high > low and nums[high] == temp[3]) high--;
                    }
                }
                while(j+1 < n and nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n and nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};
