// Given an array nums of distinct integers, return all the possible permutations.
// You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

// Slower Approach

class Solution {
public:
    unordered_map<int, int> m;
    vector<vector<int>> ans;
    
    void backtrack(vector<int> &nums, vector<int> &temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(m[nums[i]] != 0) continue;
            temp.push_back(nums[i]);
            m[nums[i]]++;
            backtrack(nums, temp);
            m[nums[i]]--;
            temp.pop_back();
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, temp);
        return ans;
    }
};

// Optimized Approach
// MUCH faster
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); ++i){
            swap(nums[i], nums[index]);
            backtrack(ans, nums, index+1);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0);
        return ans;
    }
};

