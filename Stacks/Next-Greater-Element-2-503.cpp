// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
// return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in 
// the array, which means you could search circularly to find its next greater number. If it doesn't
//   exist, return -1 for this number.

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

// Constraints:

// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109
  
class Solution {
public:    
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        stack<int> st;
        for(int i=n-1; i>=0; --i){            
            while(!st.empty() and nums[i]>=st.top())
                st.pop();
            st.push(nums[i]);
        }
        for(int i=n-1; i>=0; --i){
            if(st.empty()) v.push_back(-1);
            else{
                while(!st.empty() and nums[i]>=st.top())
                    st.pop();
                if(st.empty()) v.push_back(-1);
                else v.push_back(st.top());
            }
                st.push(nums[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

// Method 2
class Solution {
public:    
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for(int i = (2*n) - 1; i >= 0; i--){
            while(!st.empty() and st.top() <= nums[i % n])
                st.pop();
            nge[i % n] = st.empty() ? -1 : st.top();
            st.push(nums[i % n]);
        }
        return nge;
    }
};