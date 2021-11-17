// Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer
//  matrix mat where mat[i][j] == i * j (1-indexed).
// Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table. 

// Example 1:
// Input: m = 3, n = 3, k = 5
// Output: 3
// Explanation: The 5th smallest number is 3.
// Example 2:
// Input: m = 2, n = 3, k = 6
// Output: 6
// Explanation: The 6th smallest number is 6. 

// Constraints:
// 1 <= m, n <= 3 * 104
// 1 <= k <= m * n

class Solution {
    public boolean countSmallerOrEqual(int x, int m, int n, int k){
        int count = 0;
        for(int i = 1; i <= m; i++)
            count += Math.min(n, x / i);
        return count >= k;
    }
    
    public int findKthNumber(int m, int n, int k) {
        int low = 1, high = (m + 1)*(n + 1);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(!countSmallerOrEqual(mid, m, n, k))
                low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
}