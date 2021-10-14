// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = []
// Output: 0
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
// Example 4:

// Input: matrix = [["1"]]
// Output: 1
// Example 5:

// Input: matrix = [["0","0"]]
// Output: 0

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 0 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

// ADITYA VERMA APPROACH 🤩

class Solution {
public:
     int ans = INT_MIN;        
    
     int largestRectangleArea(vector<int> &heights) {
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
    
    int maximalRectangle(vector<vector<char>>& matrix){
        if(matrix.size() == 0 ) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m,0);        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            ans = max(ans, largestRectangleArea(heights)); 
        }
       return ans;
    }
};


// APPROACH 2
class Solution {
public:
    int largestRectangleArea(vector<int>heights) {
        stack<int> st;
        heights.push_back(0);
        int ans = 0, n = heights.size();
        int i = 0;
        while(i<n){
            while(!st.empty() and heights[i]<=heights[st.top()]){
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size());
        // for the first row, fill every cell/column
        for(int i=0; i<matrix[0].size(); i++){
            heights[i] = matrix[0][i]-'0';
        }
        int area = largestRectangleArea(heights);
        for(int i=1; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]-'0'==1){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            
            area = max(area, largestRectangleArea(heights));
           // cout<< area <<endl;
        }
        return area;
    }
};

