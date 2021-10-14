// Given an array nums of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by k.
// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        
        int sum = 0, ans = 0;
        for(int i=0; i < nums.size(); ++i) {
            sum += nums[i];
            
            // in cpp, mod gives negative value (unlike Python)
            // i.e in Python -2 % 3 = 1, in c++: -2 % 3 = -2
            int target = sum % k;
            if(target < 0)
                target += k;
            
            if(m.count(target) != 0) {
                ans += m[target];
                m[target] += 1;
            } else
                m[target] = 1;
        }
        
        return ans;
    }
};
