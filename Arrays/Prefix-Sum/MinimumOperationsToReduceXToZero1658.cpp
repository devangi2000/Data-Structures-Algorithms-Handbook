// You are given an integer array nums and an integer x. In one operation, you can either remove the 
// leftmost or the rightmost element from the array nums and subtract its value from x. Note that this
//  modifies the array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
// Example 1:
// Input: nums = [1,1,4,2,3], x = 5
// Output: 2
// Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
// Example 2:

// Input: nums = [5,6,7,8,9], x = 4
// Output: -1
// Example 3:

// Input: nums = [3,2,20,1,1,3], x = 10
// Output: 5
// Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 
// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
// 1 <= x <= 109

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> m; // {num, index}
        int n = nums.size(), sum = 0, target = 0, longest = INT_MIN;
        for(int i = 0; i < n; i++){
            sum+=nums[i];
        }
        if(x>sum) return -1;
        target = sum - x;
        if(target == 0) return n;
        m[0] = -1;
        int prefix = 0;
        for(int i = 0; i < n; i++){
            prefix += nums[i];
            if(m.find(prefix-target) != m.end()){
                longest = max(longest, i - m[prefix-target]);
            }
            m[prefix] = i;
        }        
        return longest == INT_MIN ? -1 : n-longest; 
    }
};