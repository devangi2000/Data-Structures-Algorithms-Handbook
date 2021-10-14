// Given an array Arr (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. 
// The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in 
// the output i.e you have to iterate on the original array only.

// Example 1:

// Input:
// N = 7
// Arr[] = {4, 3, 7, 8, 6, 2, 1}
// Output: 3 7 4 8 2 6 1
// Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
// Example 2:

// Input:
// N = 4
// Arr[] = {1, 4, 3, 2}
// Output: 1 4 2 3
// Explanation: 1 < 4 > 2 < 3
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZag() which takes the array of integers arr and n as parameters and returns void. You need to modify the array itself.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 0 <= Arri <= 106

class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) {
	    // code here
	    for(int i=0; i<n-1; ++i){
	       if(i%2==0){
	            if(arr[i] > arr[i+1])
	                swap(arr[i], arr[i+1]);
	       }
	       else if(arr[i] < arr[i+1])
	            swap(arr[i+1], arr[i]);
	       }
	}
};
