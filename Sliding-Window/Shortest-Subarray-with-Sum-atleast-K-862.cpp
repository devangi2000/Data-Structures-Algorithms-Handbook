// Given an integer array nums and an integer k, return the
// length of the shortest non-empty subarray of nums with a 
// sum of at least k. If there is no such subarray, return -1.
// A subarray is a contiguous part of an array. 

// Example 1:

// Input: nums = [1], k = 1
// Output: 1
// Example 2:

// Input: nums = [1,2], k = 4
// Output: -1
// Example 3:

// Input: nums = [2,-1,2], k = 3
// Output: 3

// Constraints:

// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105
// 1 <= k <= 109

class Solution {
public:
    int shortestSubarray(vector<int> A, int K) {
        int n = A.size(), res = n+1;
        deque<int> dq;
        for(int i=0; i<n; ++i){
            // calculating prefix sum in place
            if(i > 0)
                A[i] += A[i-1];
            if(A[i] >= K)
                res = min(res, i+1);
            while(!dq.empty() and A[i] - A[dq.front()] >= K){
                res = min(res, i - dq.front());
                dq.pop_front();
            }
//The second for loop basically takes care of negative numbers that would otherwise mess up the first loop.
            while(!dq.empty() and A[i] <= A[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res <= n ? res : -1;
    }
};
