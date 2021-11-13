// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have to 
// wait after the ith day to get a warmer temperature. If there is no future day 
// for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 
// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100
// Method 1
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size());
        stack<int> st;
        for(int i = temps.size() - 1; i >= 0; i--){
            while(!st.empty() and temps[st.top()] <= temps[i])
                st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};




// Method 2
class Solution {
public:
    vector<int> v;
    stack<pair<int,int>> st;
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        for(int i=n-1; i>=0; i--){
            if(st.empty())
                v.push_back(0);
            else{
                while(!st.empty() and temperatures[i] >= st.top().first)
                    st.pop();
                if(st.empty()) v.push_back(0);
                else v.push_back(st.top().second-i);
            }
            st.push(make_pair(temperatures[i], i));
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

