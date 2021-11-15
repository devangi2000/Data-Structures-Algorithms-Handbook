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


class Solution {
    int mod=(int)1e9+7;
    public int countGoodNumbers(long n) {
        long first=(n%2==0?(n/2):(n/2)+1);//deciding n/2 or n/2+1 depending on n is even or odd
        long second=n/2;//second power would be n/2 only irrespective of even or odd
        long mul1=power(5,first)%mod;//5 power n/2
        long mul2=power(4,second)%mod;//4 power n/2
        long ans=1;
        ans=(ans*mul1)%mod;//computing total product
        ans=(second!=0)?(ans*mul2)%mod:ans;//computing total product
        return (int)(ans%mod);
    }
    public long power(long x,long y){// this method computes pow(x,y) in O(logn) using divide & conquer
        long temp;
        if(y==0) return 1;//base case (x power 0 = 1)
        temp=power(x,y/2);//computing power for pow(x,y/2) -> divide & conquer step
        if(y%2==0) return (temp*temp)%mod; //using that result of subproblem (2 power 2 = 2 power 1 * 2 power 1)
        else return (x*temp*temp)%mod;
    }
}