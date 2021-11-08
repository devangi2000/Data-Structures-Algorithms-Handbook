// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

// Example 1:

// Input: 

// Output: 1
// Explanation: The given graph can be colored 
// in two colors so, it is a bipartite graph.
// Example 2:

// Input:

// Output: 0
// Explanation: The given graph cannot be colored 
// in two colors such that color of adjacent 
// vertices differs. 
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph and returns a boolean value true if graph is bipartite otherwise returns false.
 

// Expected Time Complexity: O(V)
// Expected Space Complexity: O(V)

// Constraints:
// 1 ≤ V, E ≤ 105

class Solution
{
    public boolean bfsCheck(ArrayList<ArrayList<Integer>>adj, int[] color, int node){
        if(color[node] == -1)
            color[node] = 1;
        for(int it : adj.get(node)){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                if(!bfsCheck(adj, color, it))
                    return false;
            }
            else if(color[it] == color[node]) return false;
        }
        return true;
    }
    public boolean isBipartite(int V, ArrayList<ArrayList<Integer>>adj)
    {
        int[] color = new int[V];
        Arrays.fill(color, -1);
        for(int i = 0; i < V; i++){
            if(color[i] == -1)
                if(!bfsCheck(adj, color, i) == true) 
                    return false;
        }
        return true;
    }
}