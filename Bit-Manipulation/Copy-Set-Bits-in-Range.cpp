// https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1#
// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. Find the set bits of y in range [l, r] and set these bits in x also.

// Example 1:

// Input: 
// X = 44, Y = 3 
// L = 1,  R = 5
// Output: 47
// Explaination: presenation of 44 and 3 are 
// 101100 and 11. So in the range 1 to 5 there 
// are two set bits. If those are set in 44 
// it will become 101111 = 47.

// Example 2:

// Input: 
// X = 16, Y = 2
// L = 1,  R = 3
// Output: 18
// Explaination: representation of 16 and 2 
// are 10000 and 10. If the mentioned rule is 
// followed then 16 will become 10010 = 18.

// Expected Time Complexity: O(r - l)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ x, y ≤ 109
// 1 ≤ l ≤ r ≤ 32

class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        int mask = 1;
        mask = mask << (r - l + 1);
        if(r-l+1==32) mask=(1<<31);
        mask--;
        mask = mask << (l - 1);
        
        mask = mask & y;
        x = mask | x;
        
        return x;
    }
};
