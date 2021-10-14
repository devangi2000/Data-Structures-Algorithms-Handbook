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
public:
    void backtrack(vector<vector<int>> &ans, vector<int> temp, vector<int> &nums, vector<bool> &visited){
        if(nums.size() == temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){            
            if(visited[i] || (i > 0 and nums[i] == nums[i-1] and !visited[i-1])) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            backtrack(ans, temp, nums, visited);            
            visited[i] = false;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(ans, temp, nums, visited);
        return ans;
    }
};
