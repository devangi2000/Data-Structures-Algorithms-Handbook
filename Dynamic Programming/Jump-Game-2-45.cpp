// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index. 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, left = 0, right = 0;
        while(right < nums.size()-1){
            int farthest = 0;
            for(int i = left; i <= right; i++){
                farthest = max(farthest, i + nums[i]);
            }
            left = right + 1;
            right = farthest;
            jumps++;
        }
        return jumps;
    }
}; 

 // LINEAR TC
class Solution{
  public:
    int minJumps(int arr[], int N){
        int jumps = 1, maxreachable = arr[0], step = arr[0];
        if(N == 1)  return 0;
        if(arr[0] == 0) return -1;
        for(int i = 1; i < N; i++){
            if(i == N-1)
                return jumps;
            maxreachable = max(maxreachable, i + arr[i]);
            step--;
            if(step == 0)
            {
                jumps++;
                if(i >= maxreachable)
                    return -1;
                step = maxreachable - i;
            }
        }
    }
};