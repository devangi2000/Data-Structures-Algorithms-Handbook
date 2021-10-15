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


// USE THE MAXIMUM HISTOGRAM AREA CONCEPT HERE
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

