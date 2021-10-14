// Given an unsorted array arr[] of size N having both negative and positive integers.
//   The task is place all negative element at the end of array without changing the
//   order of positive element and negative element.

// Example 1:

// Input : 
// N = 8
// arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
// Output : 
// 1  3  2  11  6  -1  -7  -5

// Example 2:

// Input : 
// N=8
// arr[] = {-5, 7, -3, -4, 9, 10, -1, 11}
// Output :
// 7  9  10  11  -5  -3  -4  -1

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
 
// Constraints:
// 1 ≤ N ≤ 105
// -105 ≤ arr[] ≤ 105

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int i = n, j = n-1;
        while(i >= 0 and j >= 0){
            if(arr[j] < 0){
                i--;
                swap(arr[i], arr[j]);
            }
            j--;
        }
        return;
    }
};
