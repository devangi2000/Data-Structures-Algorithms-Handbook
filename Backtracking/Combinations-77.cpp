// Given two integers n and k, return all possible combinations
// of k numbers out of the range [1, n].
// You may return the answer in any order.

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]Example 2:

// Input: n = 1, k = 1
// Output: [[1]]

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int n, int k, int start, vector<int> temp){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i = start; i <= n; i++){
           temp.push_back(i);
           backtrack(n, k, i + 1, temp);
           temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k){
        vector<int> temp;
        if(n < k)
            return ans;
        backtrack(n, k, 1, temp);
        return ans;
    }
};

