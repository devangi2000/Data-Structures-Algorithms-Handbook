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
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> temp, int index){
        ans.push_back(temp);
        for(int i = index; i < nums.size(); ++i){
            temp.push_back(nums[i]);
            backtrack(ans, nums, temp, i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, nums, temp, 0);
        return ans;
    }
};


// Iterative Method and faster
class Solution {
public:    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for(int num : nums){
            int n = ans.size();
            for(int i = 0; i < n; i++){
                ans.push_back(ans[i]);
                ans.back().push_back(num);
            }
        }
        return ans;
    }
};

