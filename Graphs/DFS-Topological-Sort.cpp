// https://practice.geeksforgeeks.org/problems/topological-sort/1#
// Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.
// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.
// Example 2:

// Input:

// Output:1
 
// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).


// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ (N*(N-1))/2

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void dfs(int node, vector<int> &visited, stack<int> &st,vector<int> adj[]){
	    visited[node] = 1;
	    for(auto a: adj[node]){
	        if(!visited[a])
	            dfs(a, visited, st, adj);
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> visited(V, 0);
	    for(int i=0; i<V; i++){
	        if(visited[i]==0)
	            dfs(i, visited, st, adj);
	    }
	    vector<int> v;
	    while(!st.empty()){
	        v.push_back(st.top());
	        st.pop();
	    }
	    return v;
	}
};
