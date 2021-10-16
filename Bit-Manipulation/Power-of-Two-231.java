// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#
// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.
//  Example 1:

// Input: N = 1
// Output: true
// Explanation:
// 1 is equal to 2 raised to 0 (20 = 1).
// Example 2:

// Input: N = 98
// Output: false
// Explanation: 
// 98 cannot be obtained by any power of 2.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 ≤ N ≤ 1018


// Method 1

class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n%2 == 0)
            n /= 2;
        return n == 1;
    }
}

// Method 2

class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int temp = n & (n-1);
        return temp == 0;
    }
}