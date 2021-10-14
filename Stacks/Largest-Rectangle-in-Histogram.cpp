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

/*
BRUTE FORCE APPROACH THAT WORKS BUT WILL GIVE A TLE:

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        for(int i=0; i<n; i++){
            int minh = INT_MAX;
            for(int j = i; j<n; j++){
                minh = min(minh, heights[j]);
                int l = j - i + 1;
                ans = max(ans, l*minh);                
            }
        }
        return ans;
    }
};
*/
// ADITYA VERMA'S APPROACH 🤩
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st, st2;
        vector<int> nsl, nsr;
        for(int i=0; i<heights.size(); i++){
            if(st.empty()) nsl.push_back(-1);
            else if(!st.empty() && heights[i] <= st.top().first){
                while(!st.empty() && heights[i] <= st.top().first)
                    st.pop();
                if(st.empty()) nsl.push_back(-1);
                else nsl.push_back(st.top().second);
            }
            else nsl.push_back(st.top().second);
            st.push({heights[i], i});
        }
        
       for(int i=heights.size()-1; i>=0; i--){
            if(st2.empty()) nsr.push_back(heights.size());
            else if(!st.empty() && heights[i] <= st2.top().first){
                while(!st2.empty() && heights[i] <= st2.top().first)
                    st2.pop();
                if(st2.empty()) nsr.push_back(heights.size());
                else nsr.push_back(st2.top().second);
            }
            else nsr.push_back(st2.top().second);
            st2.push({heights[i], i});
        }
        reverse(nsr.begin(), nsr.end());
        int ans = INT_MIN;
        for(int i=0; i<heights.size(); i++)
            ans = max(ans, (nsr[i]-nsl[i]-1)*heights[i]);
        
        return ans;
    }
};

// OR USE THIS STACK-BASED METHOD INSTEAD; IT'S MORE OPTIMIZED THAN BRUTE FORCE TOO
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int ans = 0, n = heights.size();
        int i = 0;
        while(i<n){
            while(!st.empty() and heights[i]<heights[st.top()]){
                int index = st.top();
                int height = heights[index];
                st.pop();
                if(st.empty()){                
                    ans = max(ans, height*i);
                }
                else{
                   int width = i - st.top() - 1;
                   ans = max(ans, height*width); 
            }
         }
            st.push(i);
            i++;
       }
        return ans;
    }
};
