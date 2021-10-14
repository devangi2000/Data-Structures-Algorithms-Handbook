// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"
// Example 4:

// Input: columnNumber = 2147483647
// Output: "FXSHRXW"
 

// Constraints:

// 1 <= columnNumber <= 231 - 1

class Solution {
public:
    string convertToTitle(int n) 
    {
        string ans = "";
        while(n > 0){
            int temp = n % 26;
            if(temp == 0){
                ans += 'Z';
                n /= 26;
                n -= 1;
            }
            else{
                ans += (temp - 1) + 'A';
                n /= 26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
