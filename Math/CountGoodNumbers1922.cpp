// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
// Example 2:

// Input: n = 4
// Output: 400
// Example 3:

// Input: n = 50
// Output: 564908303
 

// Constraints:

// 1 <= n <= 1015

#define ll long long
int p = 1e9 + 7;
class Solution {
public:
    ll power(long long x, long long y){
        long long res = 1;
        x %= p;
        if(x == 0) return 0;
        while(y > 0){
            if(y & 1) res = (res*x) % p;
            y >>= 1;
            x = (x*x) % p;
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        ll count4s = n/2;
        ll count5s = n - (n/2);
        ll ans = ((power(4, count4s) % p * power(5, count5s)) % p);
        return (int) ans;
    }
};
