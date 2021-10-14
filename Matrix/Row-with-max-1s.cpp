// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
// Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

// Example 1:

// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).

// Example 2:

// Input: 
// N = 2, M = 2
// Arr[][] = {{0, 0}, {1, 1}}
// Output: 1
// Explanation: Row 1 contains 2 1's (0-based
// indexing).

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N, M ≤ 103
// 0 ≤ Arr[i][j] ≤ 1 
  
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int j = m-1, i = 0, row = -1;
        while(j >= 0 and arr[0][j] == 1){
            j--;
            row = 0;
        }
        for(int i = 1; i < n; i++){
            if(arr[i][j] == 0) continue;
            else{
               while(arr[i][j] == 1 and j >= 0){
                 j--;
                 row = i;  
               }
            }
        }
        return row;
	}
};
