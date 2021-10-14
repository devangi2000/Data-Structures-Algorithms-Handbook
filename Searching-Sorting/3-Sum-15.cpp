// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets. 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// Brute Force that gives TLE

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set <vector<int>> uset;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<n-2; i++)
//         {
//             vector<int> temp;                
//             for(int j=i+1; j<n-1; j++)
//             {
//                 for(int k=j+1; k<n; k++)
//                 {
//                     if(i!=j && j!=k && i!=k)
//                     {
//                         if(nums[i] + nums[j] + nums[k] == 0)
//                         {
//                             temp.push_back(nums[i]);
//                             temp.push_back(nums[j]);
//                             temp.push_back(nums[k]);
//                             uset.insert(temp);
//                             temp.clear();
//                         }
//                     }   
//                 }
//             }
//         }
//      vector<vector<int>> result (uset.begin(), uset.end());
//      return result;
//     }
// };

// Sorting + 2-pointer approach
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i = 0; i < n-2; ++i){
        if(i == 0 || (i > 0 and nums[i] != nums[i-1])){
            int low = i+1, high = n-1, sum = 0 - nums[i];
            while(low < high){
                if(nums[low] + nums[high] == sum){
                    ans.push_back({nums[low], nums[i], nums[high]});
                    while(low < high and nums[low] == nums[low+1]) low++;
                    while(high > low and nums[high] == nums[high-1]) high--;
                    low++; high--;
                }
                else if(nums[low] + nums[high] < sum){
                    low++;
                }
                else high--;
            }
        }
    }
    return ans;
  }
};
