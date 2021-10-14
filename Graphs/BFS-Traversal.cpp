// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
// Example 1:

// Input:

// Output: 0 1 2 3 4
// Explanation: 
// 0 is connected to 1 , 2 , 3.
// 2 is connected to 4.
// so starting from 0, it will go to 1 then 2
// then 3.After this 2 to 4, thus bfs will be
// 0 1 2 3 4.
// Example 2:

// Input:

// Output: 0 1 2
// Explanation:
// 0 is connected to 1 , 2.
// so starting from 0, it will go to 1 then 2,
// thus bfs will be 0 1 2 3 4. 

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ V, E ≤ 104

// Company Tags
// Topic Tags
// Related Courses
// Related Interview Experiences

// If you are facing any issue on this page. Please let us know.

// Output Window
class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    queue<int> q;
	    vector<int> v;
	    q.push(0);
	    vector<int> visited(V, 0);
	    visited[0] = 1;
	    while(!q.empty()){
	        int curr = q.front();
	        q.pop();
	        v.push_back(curr);
	        for(auto ele: adj[curr]){
	            if(!visited[ele]){
	            visited[ele] = 1;
	            q.push(ele);
	            }
	        }
	    }
	    return v;
	}
};
