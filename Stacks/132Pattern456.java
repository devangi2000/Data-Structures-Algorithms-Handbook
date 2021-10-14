// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] 
// and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.
// Example 2:
// Input: nums = [3,1,4,2]
// Output: true
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
// Example 3:
// Input: nums = [-1,3,2,0]
// Output: true
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
//  Constraints:
// n == nums.length
// 1 <= n <= 2 * 105
// -109 <= nums[i] <= 109

// METHOD 1

class Solution {
    public boolean find132pattern(int[] nums) {
        int s3 = Integer.MIN_VALUE;
        Stack<Integer> st = new Stack<>();
        for(int i = nums.length - 1; i >= 0; i--){
            if(nums[i] < s3) return true;
            else while(!st.isEmpty() && nums[i] > st.peek()){
                s3 = st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
}


// METHOD 2

class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] mini = new int[n];
        mini[0] = nums[0];
        for(int i = 1; i < n; i++)
            mini[i] = Math.min(mini[i-1], nums[i]);
        Stack<Integer> st = new Stack<>();
        for(int i = n-1; i >= 0; i--){
            if(nums[i] > mini[i]){
                while(!st.isEmpty() && st.peek() <= mini[i])
                    st.pop();
                if(!st.isEmpty() && st.peek() < nums[i]) return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
}