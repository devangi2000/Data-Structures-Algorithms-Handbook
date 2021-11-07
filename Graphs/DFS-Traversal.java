// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..

// Example 1:

// Input:

// Output: 0 1 2 4 3
// Explanation: 
// 0 is connected to 1, 2, 4.
// 1 is connected to 0.
// 2 is connected to 0.
// 3 is connected to 0.
// 4 is connected to 0, 3.
// so starting from 0, it will go to 1 then 2
// then 4, and then from 4 to 3.
// Thus dfs will be 0 1 2 4 3.
// Example 2:

// Input:

// Output: 0 1 2 3
// Explanation:
// 0 is connected to 1 , 3.
// 1 is connected to 2. 
// 2 is connected to 1.
// 3 is connected to 0. 
// so starting from 0, it will go to 1 then 2
// then back to 0 then 0 to 3
// thus dfs will be 0 1 2 3. 

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 ≤ V, E ≤ 104


class Solution {
    public void dfs(int i, ArrayList<ArrayList<Integer>> adj, int[] visited, ArrayList<Integer> ans){
        visited[i] = 1;
        ans.add(i);
        for(int num : adj.get(i)){
            if(visited[num] == 0) 
                dfs(num, adj, visited, ans);
        }
        return;
    }
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] visited = new int[V];
        ArrayList<Integer> ans = new ArrayList<>();
        dfs(0, adj, visited, ans);
        return ans;
    }
}