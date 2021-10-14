// Given an integer num, return a string representing its hexadecimal representation. 
// For negative integers, two’s complement method is used.
// All the letters in the answer string should be lowercase characters, and there should
//  not be any leading zeros in the answer except for the zero itself.
// Note: You are not allowed to use any built-in library method to directly solve this problem.

// Example 1:
// Input: num = 26
// Output: "1a"
// Example 2:
// Input: num = -1
// Output: "ffffffff"

// Constraints:
// -231 <= num <= 231 - 1

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string res;
        int count = 0;
        while(num and count < 8){
            int temp = num & 15;
            if(temp < 10)
                res.push_back('0' + temp);
            else res.push_back('a' + temp - 10);
            num = num >> 4;
            count++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};