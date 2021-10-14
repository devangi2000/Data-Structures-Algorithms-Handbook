// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#
// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

// Example 1:

// Input:

// Output:
// 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.
// Example 2:

// Input:

// Output:
// 5
// Explanation:
// Only one Spanning Tree is possible
// which has a weight of 5.
 

// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the distance between edge i and j is w.
 

// Expected Time Complexity: O(ElogV).
// Expected Auxiliary Space: O(V2).
 

// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// Graph is connected and doesn't contain self loops & multiple edges.


class Solution
{
	public:
	int spanningTree(int V, vector<vector<int>> adj[])
    {
      vector<bool> visited(V, false);
      int cost = 0;
      vector<int> key(V, INT_MAX);
      key[0] = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({0, 0}); // weight, node
      while(!pq.empty()){
          auto curr = pq.top();
          pq.pop();
          int v = curr.second;
          int weight = curr.first;
          if(!visited[v]){
              visited[v] = true;
              cost += weight;
              for(auto it : adj[v]){
                  if(!visited[it[0]]){
                        pq.push({it[1], it[0]});
                  }
              }
          }
      }
      return cost;
    }
};
