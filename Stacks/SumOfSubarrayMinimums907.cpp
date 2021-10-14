// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray
//  of arr. Since the answer may be large, return the answer modulo 109 + 7.

// Example 1:
// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:
// Input: arr = [11,81,94,43,3]
// Output: 444
//  Constraints:
// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> left, right;
        int n = arr.size(), ans = 0, mod = 1e9 + 7;
        vector<int> nsl(n), nsr(n);
        for(int i = 0; i < n; i++){
            int count = 1;
            while(!left.empty() and left.top().first > arr[i]){
                count += left.top().second;
                left.pop();
            }                
            left.push({arr[i], count});
            nsl[i] = count;
        }
        
        for(int i = n - 1; i >= 0; i--){
            int count = 1;
            while(!right.empty() and right.top().first >= arr[i]){
                count += right.top().second;
                right.pop();
            }
            right.push({arr[i], count});
            nsr[i] = count;
        }
        
        for(int i = 0; i < n; i++)
            ans = (ans + (long)arr[i]*nsl[i]*nsr[i])%mod;
        return ans;        
    }
};
