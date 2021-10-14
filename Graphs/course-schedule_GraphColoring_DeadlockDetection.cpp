// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
// Deadlock Detection & Graph Coloring

class Solution {
public:
    bool isCycle(vector<vector<int>> &adj, vector<int> &visited, int node){
        if(visited[node]==2) return true;
        visited[node] = 2;
        for(int i=0; i<adj[node].size(); i++)
            if(visited[adj[node][i]]!=1)
                if(isCycle(adj, visited, adj[node][i]))
                    return true;
        
        visited[node] = 1;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=1; i<numCourses; i++)
            if(visited[i]==0)
                if(isCycle(adj, visited, i))
                    return false;
        
        return true;
    }
};
