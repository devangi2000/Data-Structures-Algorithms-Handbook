// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

class Solution {
public:
    vector<vector<int>> res;
    void solve(const vector<int>& candidates, int index, int target, vector<int> temp){
        if(target == 0){
            res.emplace_back(temp);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(target - candidates[i] >= 0){
                temp.push_back(candidates[i]);
                solve(candidates, i+1, target - candidates[i], temp);
                temp.pop_back();
            }
            while((i+1) < candidates.size() and candidates[i]==candidates[i+1])
                i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, 0, target, temp);
        return res;
    }
};


// ORRRRRRR
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int> &candidates, int target, vector<int> temp, int index){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); ++i){
            if(i > index and candidates[i] == candidates[i-1]) continue;
            if(target < candidates[i]) break;
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, temp, 0);
        return res;
    }
};
