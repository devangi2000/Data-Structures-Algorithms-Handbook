// Given an array of integers, every element appears thrice except for one which occurs once.

// Find that element which does not appear thrice.

// Note: Your algorithm should have a linear runtime complexity.

// Could you implement it without using extra memory?

// Input Format:

//     First and only argument of input contains an integer array A
// Output Format:

//     return a single integer.
// Constraints:

// 2 <= N <= 5 000 000  
// 0 <= A[i] <= INT_MAX
// For Examples :

// Example Input 1:
//     A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
// Example Output 1:
//     4
// Explanation:
//     4 occur exactly once
// Example Input 2:
//     A = [0, 0, 0, 1]
// Example Output 2:
//     1

public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public int singleNumber(final List<Integer> A) {
        int num = 0;
        int count = 0;
        for(int i=0;i<32;++i) {
            count = 0;
            for(int a : A) {
                if((a & 1 << i) != 0) {
                    count++;
                }
            }
            if(count%3 != 0) {
                num+=1<<i;
            }
        }
        return num;
    }
}