// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

// Example 1:

// Input: num = 3
// Output: "III"
// Example 2:

// Input: num = 4
// Output: "IV"
// Example 3:

// Input: num = 9
// Output: "IX"
// Example 4:

// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 5:

// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4. 

// Constraints:
// 1 <= num <= 3999

// METHOD 1
class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string res = "";
        int i = 12;
        while(num > 0){
            int quo = num / nums[i];
            num = num % nums[i];
            while(quo){
                res += symbols[i];
                quo--;
            }
            i--;
        }
        return res;
    }
};


// METHOD 2

class Solution {
public:
    string intToRoman(int A) {
        string s = "";
int m = A / 1000;
for(int i = 1;i<=m;i++)
s += "M";
A %= 1000;
if(A >= 900)
{
    s += "CM";
    A -= 900;
}
if(A >= 500)
{
    s += "D";
    A -= 500;
}
if(A >= 400)
{
    s += "CD";
    A -= 400;
}
if(A >= 100)
{
    m = A/100;
    for(int i=1;i<=m;i++)
    s += "C";
    A %= 100;
}
if(A >= 90)
{
    s += "XC";
    A -= 90;
}
if(A >= 50)
{
    s += "L";
    A -= 50;
}
if(A >= 40)
{
    s += "XL";
    A -= 40;
}
if(A >= 10)
{
    m = A/10;
    for(int i=1;i<=m;i++)
    s += "X";
    A %= 10;
}
if(A == 9)
{
    s += "IX";
    A -= 9;
}
if(A >= 5)
{    
    s += "V";
    A -= 5;
}
if(A == 4)
s += "IV";
else if(A > 0)
{
    for(int i=1;i<=A;i++)
    s += "I";
}
return s;
    }
};