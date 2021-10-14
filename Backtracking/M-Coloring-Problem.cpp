// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

// Given an undirected graph and an integer M. The task is to determine if the graph can be colored 
// with at most M colors such that no two adjacent vertices of the graph are colored with the same color.
//   Here coloring of a graph means the assignment of colors to all vertices. 
//   Print 1 if it is possible to colour vertices and 0 otherwise.

// Example 1:

// Input:
// N = 4
// M = 3
// E = 5
// Edges[] = {(1,2),(2,3),(3,4),(4,1),(1,3)}
// Output: 1
// Explanation: It is possible to colour the
// given graph using 3 colours.
// Example 2:

// Input:
// N = 3
// M = 2
// E = 3
// Edges[] = {(1,2),(2,3),(1,3)}
// Output: 0

// Expected Time Complexity: O(MN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 20
// 1 <= E <= (N*(N-1))/2
// 1 <= M <= N

// Note: The given inputs are 1-base indexed but you have to consider the graph given in the adjacency matrix/list as 0-base indexed.

bool isSafe(bool graph[101][101], vector<int> &color, int u, int i, int V){
    for(int v = 0; v < V; v++){
        if(graph[u][v] && color[v]==i)
            return false;
    }
    return true;
}

bool solve(bool graph[101][101], vector<int> &color, int u, int m, int V){
    if(u == V) return true;
    for(int i=0; i<m; i++){
        if(isSafe(graph, color, u, i, V)){
            color[u] = i;
            bool flag = solve(graph, color, u+1, m, V);
            if(flag) return true;
        }
    }
    color[u] = -1;
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> color(V, -1);
    int u=0;
    return solve(graph, color, u, m, V);
}
