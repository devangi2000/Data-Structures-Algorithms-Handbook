// Given a positive integer num, write a function which returns True if num is a perfect square else False.
// Follow up: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: num = 16
// Output: true
// Example 2:

// Input: num = 14
// Output: false

// Constraints:
// 1 <= num <= 2^31 - 1

class Solution {
    public boolean isPerfectSquare(int num) {
        int left = 1, right = num;
        while(left <= right){
        long mid = left + (right - left) / 2;
        if(mid*mid == num)
            return true;
        else if(mid*mid > num)
            right = (int)mid - 1;
        else left = (int)mid + 1;
        }
        return false;
    }
}