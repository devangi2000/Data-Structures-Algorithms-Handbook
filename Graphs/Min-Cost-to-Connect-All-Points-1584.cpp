// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.


// Example 1:
// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation:

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:
// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
// Example 3:
// Input: points = [[0,0],[1,1],[1,0],[-1,1]]
// Output: 4
// Example 4:
// Input: points = [[-1000000,-1000000],[1000000,1000000]]
// Output: 4000000
// Example 5:
// Input: points = [[0,0]]
// Output: 0 

// Constraints:

// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.
// USING PRIM'S MST
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, 1e8);
        int cost = 0, curr = 0;
        for(int i=0; i<n-1; i++){
            visited[curr] = true;
            for(int j=0; j<n; j++){
                if(!visited[j]){
                    dist[j] = min(dist[j], abs(points[curr][0] - points[j][0]) + abs(points[curr][1] - points[j][1]));
                }
            }
            curr = min_element(dist.begin(), dist.end()) - dist.begin();
            cost += dist[curr];
            dist[curr] = 1e8;
        }
        return cost;
    }
};

// USING KRUSKAL'S UNION-FIND ALGO
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int x){
        if(parent[x] == -1)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void unite(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a == b){
           return;
        }
        else if(rank[a] > rank[b]){
            parent[b] = a;
        }
        else {                  //if(rank[b] > rank[a])
            parent[a] = b;
            if(rank[a] == rank[b])
                rank[b]++;
        }
    }
     int minCostConnectPoints(vector<vector<int>>& points){        
       int n = points.size(), ans = 0;
         rank = vector<int>(n, 0);
         parent = vector<int>(n, -1);
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
         for(int i=0; i<n; i++){
             for(int j=i+1; j<n; j++){
                 int weight = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                 pq.push({weight, {i, j}});
             }
         }
        while(!pq.empty()){
             auto curr = pq.top();
             pq.pop();
             int weight = curr.first;
             int u = curr.second.first;
             int v = curr.second.second;
             if(findParent(u) != findParent(v)){
                 unite(u, v);
                 ans += weight;
             }
         }
         return ans;
    }
};
