// A positive integer is magical if it is divisible by either a or b.

// Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 1, a = 2, b = 3
// Output: 2
// Example 2:

// Input: n = 4, a = 2, b = 3
// Output: 6
// Example 3:

// Input: n = 5, a = 2, b = 4
// Output: 10
// Example 4:

// Input: n = 3, a = 6, b = 4
// Output: 8
 

// Constraints:

// 1 <= n <= 109
// 2 <= a, b <= 4 * 104



class Solution {
    public int nthMagicalNumber(int N, int A, int B) {
        int MOD = 1_000_000_007;
        int L = A / gcd(A, B) * B;

        long lo = 0;
        long hi = (long) N * Math.min(A, B);
        while (lo < hi) {
            long mi = lo + (hi - lo) / 2;
            // If there are not enough magic numbers below mi...
            if (mi / A + mi / B - mi / L < N)
                lo = mi + 1;
            else
                hi = mi;
        }

        return (int) (lo % MOD);
    }

    public int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }
}