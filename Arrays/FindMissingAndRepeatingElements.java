// You are given an array of size ‘N’. The elements of the array are in the range from 1 to ‘N’.
// Ideally, the array should contain elements from 1 to ‘N’. But due to some miscalculations, there is a number R in the range [1, N] which appears in the array twice and another number M in the range [1, N] which is missing from the array.
// Your task is to find the missing number (M) and the repeating number (R).
// For Example:
// Consider an array of size six. The elements of the array are { 6, 4, 3, 5, 5, 1 }. 
// The array should contain elements from one to six. Here, 2 is not present and 5 is occurring twice. Thus, 2 is the missing number (M) and 5 is the repeating number (R). 
// Follow Up
// Can you do this in linear time and constant additional space? 
// Input Format
// The first line of input contains an integer T, the number of test cases.
// The first line of every test case contains an integer ‘N’ denoting the size of the array.
// The second line of every test case contains ‘N’ space-separated integers.
// Output Format:
// For every test case, print the missing number (M) and the repeating number (R) separated by a single space. 
// The output of each test case is printed in a separate line.
// Note
// You don’t have to print anything, it has already been taken care of. Just implement the function. 
// You have to return a pair whose first element is the missing number ‘M’ and the second element is the repeating number ‘R’. 
// Constraints:
// 1 <= T <= 10    
// 2 <= N <= 5 * 10^4
// 1 <= data <= N

// Where ‘T’ is the number of test cases, ‘N’ is the size of the array and ‘data’ denotes the value of the elements of the array. 
// Sample Input 1:
// 1 
// 5
// 1 3 5 4 4
// Sample Output 1:
// 2 4
// Explanation Of Sample Input 1:
// As we can clearly see, among all the numbers from 1 to 5, 2 is not present and 4 is occurring twice. Thus, 2 and 4 are missing and repeating numbers respectively. 
// Sample Input 2:
// 2
// 10
// 4 5 2 9 8 1 1 7 10 3
// 7
// 7 5 3 2 1 6 6 
// Sample Output 2:
// 6 1 
// 4 6

/*
    Time complexity: O(N) 
	Space complexity: O(1)
	
	Where N is the length of the given array. 
	
*/

import javafx.util.Pair;
import java.util.ArrayList;

public class Solution {
    public static Pair<Integer, Integer> missingAndRepeating(ArrayList<Integer> arr, int n) {
        int findXOR = 0;

        // Calculating the XOR of all the numbers from 1 to n
        for (int i = 1; i <= n; i += 1) {
            findXOR ^= i;
        }

        // Calculating the XOR of all the elements of the array
        for (int i = 0; i < n; i += 1) {
            findXOR ^= arr.get(i);
        }

        // last set bit of findXOR
        int bitIndex = findXOR & ~(findXOR - 1);

        int bitSet = 0, bitNotSet = 0;

        // Dividing the elements of the array in two sets, bitSet and bitNotSet
        for (int i = 0; i < n; i++) {
            if ((arr.get(i) & bitIndex) > 0) {
                bitSet = bitSet ^ arr.get(i);
            }

            else {
                bitNotSet = bitNotSet ^ arr.get(i);
            }
        }

        // Dividing the elements from 1 to n in two sets
        for (int i = 1; i <= n; i++) {
            if ((i & bitIndex) > 0) {
                bitSet = bitSet ^ i;
            }

            else {
                bitNotSet = bitNotSet ^ i;
            }
        }

        int r = 0, m = 0;

        for (int i = 0; i < n; i += 1) {
            // If bitSet is present in the array, it is the repeating number and bitNotSet
            // Is the missing number
            if (bitSet == arr.get(i)) {
                r = bitSet;
                m = bitNotSet;
                break;
            }

            // If bitNotSet is present in the array, it is the repeating number and bitSet
            // is the missing number
            if (bitNotSet == arr.get(i)) {
                r = bitNotSet;
                m = bitSet;
                break;
            }
        }

        Pair<Integer, Integer> ans = new Pair<Integer, Integer>(m, r);

        return ans;

    }

}
