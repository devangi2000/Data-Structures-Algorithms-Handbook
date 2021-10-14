// An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
// Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// Example 1:
// Input: n = 10
// Output: 9
// Example 2:
// Input: n = 1234
// Output: 1234
// Example 3:
// Input: n = 332
// Output: 299
 
// Constraints:
// 0 <= n <= 109

class Solution {
    public int monotoneIncreasingDigits(int N) {
        char[] arr = String.valueOf(N).toCharArray();
        int monotoneIncreasingEnd = arr.length - 1, n = arr.length;
        for(int i = n - 1; i > 0; i--){
            if(arr[i] < arr[i - 1]){
                monotoneIncreasingEnd = i - 1;
                arr[i - 1]--;
            }
        }
        for(int i = monotoneIncreasingEnd + 1; i < n; i++)
            arr[i] = '9';
        return Integer.parseInt(new String(arr));
    }
}

