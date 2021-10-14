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
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int monotoneIncreasingEnd = num.size() - 1, len = num.size();
        for(int i = len - 1; i > 0; i--){
            if(num[i-1] > num[i]){
                monotoneIncreasingEnd = i-1;
                num[i-1]--;
            }
        }
        for(int i = monotoneIncreasingEnd + 1; i < len; i++)
            num[i] = '9';
        return stoi(num);
    }
};