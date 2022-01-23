// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

// Example 1:


// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:


// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.
 

// Constraints:

// 1 <= n <= 105
// 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.

class Solution {
    public int components = 0, edges = 0;
    
    public void dfs(ArrayList<Integer>[] graph, boolean[] visited, int node){
        if(visited[node] == true) return;
        visited[node] = true;
        for(int child : graph[node]){
            if(visited[child] == false)
                dfs(graph, visited, child);
        }
    }
    
    public int makeConnected(int n, int[][] connections) {
        ArrayList<Integer>[] graph = new ArrayList[n+1];
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        for(int i = 0; i < n; i++)
            graph[i] = new ArrayList<Integer>();
        for(int[] edge : connections){
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
            edges++;
        }
        if(edges < n-1)
            return -1;
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                components++;
                dfs(graph, visited, i);
            }
        }
        int redundant = edges - ((components - 1) - (n - 1));
        if(redundant >= (components - 1))
            return components - 1;
        return -1;
    }
}