// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k 
// odd numbers on it.
// Return the number of nice sub-arrays.

// Example 1:
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
// Example 2:
// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There is no odd numbers in the array.
// Example 3:
// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16 

// Constraints:
// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length

// USING DEQUE

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        deque<int> dq = {-1};
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] & 1)
                dq.push_back(i);
            if(dq.size() > k + 1)
                dq.pop_front();
            if(dq.size() == k + 1)
                res += (dq.size() > 1 ? dq[1] : i) - dq[0];
        }
        return res;
    }
};

// METHOD 2

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd = 0, count = 0, ans = 0, j = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] & 1){
                odd++;
                if(odd >= k){
                    count = 1;
                    while(!(nums[j++] & 1)) count++;
                    ans += count;
                }
            }
            else if(odd >= k) ans += count;
        }
        return ans;
    }
};
