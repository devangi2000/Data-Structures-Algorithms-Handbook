/*
Given an array of integers heights representing the histogram's bar height where 
the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

// Approach 1

class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length, ans = 0;
        Stack<Integer> st = new Stack<>();
        int[] nsl = new int[n];
        int[] nsr = new int[n];
        
        for(int i = 0; i < n; i++){
            while(!st.isEmpty() && heights[i] <= heights[st.peek()])
                st.pop();
            nsl[i] = st.isEmpty() ? 0 : st.peek() + 1;
            st.push(i);
        }
        
        while(!st.isEmpty()) st.pop();
        
        for(int i = n-1; i >= 0; i--){
            while(!st.isEmpty() && heights[i] <= heights[st.peek()])
                st.pop();
            nsr[i] = st.isEmpty() ? n-1 : st.peek() - 1;
            st.push(i);
        }
        
        for(int i = 0; i < n; i++)
            ans = Math.max(ans, (nsr[i] - nsl[i] + 1) * heights[i]);
        return ans;
    }
}

// Approach 2
class Solution {
    public int largestRectangleArea(int[] heights) {
        int ans = 0, n = heights.length;
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i <= n; i++){
            while(!st.isEmpty() && (i == n || heights[i] <= heights[st.peek()])){
                int height = heights[st.pop()];
                int width = st.isEmpty() ? i : i - st.peek() - 1;
                ans = Math.max(ans, height*width);
            }
            st.push(i);
        }
        return ans;
    }
}