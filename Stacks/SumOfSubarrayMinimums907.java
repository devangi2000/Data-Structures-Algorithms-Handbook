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
    public int sumSubarrayMins(int[] arr) {
        Stack<int[]> st1 = new Stack<>(), st2 = new Stack<>();
        int n = arr.length, left[] = new int[n], right[] = new int[n];
        long ans = 0, mod = (int)1e9 + 7;
        for(int i = 0; i < n; i++){
            int count = 1;
            while(!st1.isEmpty() && st1.peek()[0] > arr[i]){
                count += st1.pop()[1];
            }
            st1.push(new int[] {arr[i], count});
            left[i] = count;
        }
        
        for(int i = n-1; i >= 0; i--){
            int count = 1;
            while(!st2.isEmpty() && st2.peek()[0] >= arr[i]){
                count += st2.pop()[1];
            }
            st2.push(new int[] {arr[i], count});
            right[i] = count;
        }
        for(int i = 0; i < n; i++)
            ans = (ans + (long)arr[i]*left[i]*right[i]) % mod;
        return (int)ans;
    }
}
