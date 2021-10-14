// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#
// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist
// in pairs whereas the other two number occur exactly once and are distinct. 
// Find the other two numbers.

// Example 1:

// Input: 
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4 
// Explanation:
// 3 and 4 occur exactly once.
// Example 2:

// Input:
// N = 1
// arr[] = {2, 1, 3, 2}
// Output:
// 1 3
// Explanation:
// 1 3 occur exactly once.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)
// Constraints:
// 1 <= length of array <= 106 
// 1 <= Elements in array <= 5 * 106
  
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xxory = 0;
        for(auto val : nums)
            xxory = xxory^val;
        int rsbm = xxory & -xxory; // we get bits that are different in non-repeating nos
        int x = 0, y = 0;
        for(int val:nums){
            if((val&rsbm)==0){
                x = x^val;
            }
            else{
                y = y^val;
            }
        }
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
