// There are n cities. Some of them are connected, while some are not. If city a is connected directly with
// city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are
// directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]


// Using Union-Find
class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int a){
        if(parent[a] == -1)
            return a;
        return parent[a] = find(parent[a]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b)
            return;
        if(rank[a] > rank[b])
            parent[b] = a;
        else if(rank[b] > rank[a])
            parent[a] = b;
        else{
            parent[a] = b;
            rank[a]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if(n==0) return 0;
        rank = vector<int>(n, 0);
        parent = vector<int>(n, -1);
        int provinces = n;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j]){
                int p1 = find(i);
                int p2 = find(j);
                if(p1 != p2 ){
                    unite(p1, p2);
                    provinces--;
                }
            }
           }
        }
        return provinces;
    }
};
