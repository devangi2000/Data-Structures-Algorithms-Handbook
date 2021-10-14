// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them.
// If it is impossible to finish all courses, return an empty array. 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
// Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]

// TOPOLOGICAL SORT: DAG only
// using DFS + Stack here

class Solution {
public:
    
    // Graph coloring: 0->not visited; 1->visited; 2->visited and processed
    bool detectCycleUtil(vector<vector<int>> &adj, vector<int> &visited, int node){
        if(visited[node] == 1)
            return true;
        if(visited[node] == 2)
            return false;
        visited[node] = 1; // Mark visited
        for(int i=0; i<adj[node].size(); i++){
            if(detectCycleUtil(adj, visited, adj[node][i]))
                return true;
        }
        
        visited[node] = 2;
        return false;
    }
    
    // Cycle detection
    bool detectCycle(vector<vector<int>> &adj, int numCourses){
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++)
            if(!visited[i])
                if(detectCycleUtil(adj, visited, i))
                    return true;
        return false;
    }
    
    // DFS and pushing to stack
    void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, stack<int> &st){
        visited[node] = true;
        for(int i=0; i<adj[node].size(); i++)
            if(!visited[adj[node][i]]) 
                dfs(adj, adj[node][i], visited, st);
        st.push(node);
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        // Make adjacency List
        for(int i=0; i<n; i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        // Detect Cycle. If present, return an empty array
        vector<int> ans;
        if(detectCycle(adj, numCourses))
            return ans;
        
        // Start Topological Sorting and store it in the stack
        stack<int> st;
        vector<bool> visited(numCourses, false);
        
        // Apply DFS and find the topological sort
        for(int i=0; i<numCourses; i++)
            if(!visited[i])
                dfs(adj, i, visited, st);
        
        // Pop the stack elements to get correct order
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
