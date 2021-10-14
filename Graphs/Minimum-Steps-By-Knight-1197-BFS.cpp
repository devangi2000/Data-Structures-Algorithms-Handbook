// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

// Note:
// The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.
// Expected Time Complexity: O(N2).
// Expected Auxiliary Space: O(N2).

// Constraints:
// 1 <= N <= 1000
// 1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
 

// Example 1:

// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output:
// 3
// Explanation:

// Knight takes 3 step to reach from 
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    int a[1001][1001];
	    if(x1==y1 and x2==y2) return 0;
	    for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
	            a[i][j] = 0;
	            
	   queue<pair<int, int>> q;
	   q.push(make_pair(x1-1, y1-1));
	   while(!q.empty()){
	       auto current = q.front();
	       q.pop();
	       int i = current.first;
	       int j = current.second;
	       if((i+1)>=0 and (i+1)<n and (j+2)>=0 and (j+2)<n and a[i+1][j+2]==0){
	           a[i+1][j+2] = a[i][j] + 1;
	           q.push(make_pair(i+1,j+2));
	       }
	       
	       if((i-1)>=0 and (i-1)<n and (j+2)>=0 and (j+2)<n and a[i-1][j+2]==0){
	           a[i-1][j+2] = a[i][j] + 1;
	           q.push(make_pair(i-1,j+2));
	       }
	       
	       if((i-2)>=0 and (i-2)<n and (j+1)>=0 and (j+1)<n and a[i-2][j+1]==0){
	           a[i-2][j+1] = a[i][j] + 1;
	           q.push(make_pair(i-2,j+1));
	       }
	       
	       if((i+2)>=0 and (i+2)<n and (j+1)>=0 and (j+1)<n and a[i+2][j+1]==0){
	           a[i+2][j+1] = a[i][j] + 1;
	           q.push(make_pair(i+2,j+1));
	       }
	       
	       if((i-1)>=0 and (i-1)<n and (j-2)>=0 and (j-2)<n and a[i-1][j-2]==0){
	           a[i-1][j-2] = a[i][j] + 1;
	           q.push(make_pair(i-1,j-2));
	       }
	       
	       if((i+1)>=0 and (i+1)<n and (j-2)>=0 and (j-2)<n and a[i+1][j-2]==0){
	           a[i+1][j-2] = a[i][j] + 1;
	           q.push(make_pair(i+1,j-2));
	       }
	       
	       
	       if((i-2)>=0 and (i-2)<n and (j-1)>=0 and (j-1)<n and a[i-2][j-1]==0){
	           a[i-2][j-1] = a[i][j] + 1;
	           q.push(make_pair(i-2,j-1));
	       }
	       
	       if((i+2)>=0 and (i+2)<n and (j-1)>=0 and (j-1)<n and a[i+2][j-1]==0){
	           a[i+2][j-1] = a[i][j] + 1;
	           q.push(make_pair(i+2,j-1));
	       }
	   }
	   return a[x2-1][y2-1];
	}
};


// Shorter Code:
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    KnightPos[0]--;
	    KnightPos[1]--;
	    
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}};
	    queue<pair<int, int>> q;
	    vector<vector<bool>> visited(N, vector<bool> (N, false));
	    
	    q.push({KnightPos[0], KnightPos[1]});
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    
	    int count = -1;
	    
	    while(!q.empty()){
	        int qsize = q.size();
	        count++;
	        
	        for(int i = 0; i < qsize; i++){
	            auto temp = q.front();
	            q.pop();
	            
	            int x = temp.first;
	            int y = temp.second;
	            
	            if(x == TargetPos[0] and y == TargetPos[1])
	                return count;
	            
	            for(int i = 0; i < 8; i++){
	                int nx = x + dir[i].first;
	                int ny = y + dir[i].second;
	                
	                if(nx >= 0 and nx < N and ny >= 0 and ny < N and !visited[nx][ny]){
	                    visited[nx][ny] = true;
	                    q.push({nx, ny});
	                }
	            }
	        }
	    }
	    
	    return -1;
	}
};
