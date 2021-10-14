// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I will tell you whether the number I picked is higher or lower
//  than your guess.
// You call a pre-defined API int guess(int num), which returns 3 possible results:
// -1: The number I picked is lower than your guess (i.e. pick < num).
// 1: The number I picked is higher than your guess (i.e. pick > num).
// 0: The number I picked is equal to your guess (i.e. pick == num).
// Return the number that I picked.

// Example 1:
// Input: n = 10, pick = 6
// Output: 6
// Example 2:
// Input: n = 1, pick = 1
// Output: 1
// Example 3:
// Input: n = 2, pick = 1
// Output: 1
// Example 4:
// Input: n = 2, pick = 2
// Output: 2

// Constraints:
// 1 <= n <= 231 - 1
// 1 <= pick <= n

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low < high){
            int mid = low + (high - low)/2;
            if(guess(mid) <= 0)
                high = mid;
            else low = mid + 1;
                
        }
        return low;
    }
};