// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
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
// ]
// Example 2:
// Input: n = 1, k = 1
// Output: [[1]]

// Constraints:
// 1 <= n <= 20
// 1 <= k <= n

class Solution {
    
    public void backtrack(int n, int k, int start, List<Integer> temp, List<List<Integer>> ans){
        if(k == temp.size()){
            ans.add(new ArrayList<Integer>(temp));
            return;
        }
        for(int i = start; i <= n; i++){
            temp.add(i);
            backtrack(n, k, i+1, temp, ans);
            temp.remove(temp.size()-1);
        }
        return;
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(n < k) return ans;
        backtrack(n, k, 1, new ArrayList<Integer>(), ans);
        return ans;
    }
}
