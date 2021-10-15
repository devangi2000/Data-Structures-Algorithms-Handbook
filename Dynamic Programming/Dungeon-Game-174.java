// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. 
// The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially 
// positioned in the top-left room and must fight his way through dungeon to rescue the princess.
// The knight has an initial health point represented by a positive integer. If at any point his health
//  point drops to 0 or below, he dies immediately.
// Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health
//  upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that
//  increase the knight's health (represented by positive integers).
// To reach the princess as quickly as possible, the knight decides to move only rightward or downward
//  in each step.
// Return the knight's minimum initial health so that he can rescue the princess.
// Note that any room can contain threats or power-ups, even the first room the knight enters and the 
// bottom-right room where the princess is imprisoned.

// Example 1:
// Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
// Output: 7
// Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
// Example 2:
// Input: dungeon = [[0]]
// Output: 1

// Constraints:
// m == dungeon.length
// n == dungeon[i].length
// 1 <= m, n <= 200
// -1000 <= dungeon[i][j] <= 1000



// Our dp looks like this:

// -2  -3   3  m      m -> denotes max 
// -5  10   1  m
// 10  30  -5  1   -> note: we have two value as 1 for the last element (I will explain this as we proceed)
//  m   m   1 m
 
//  suppose the dimensions of dungeon matirx was "r x c", for our dp will be " r+1 x c+1".
//  We will start our iteration 
//  from the value -5 that is the cell our princess is located.
//  We first have to see which value is minimum from that cell (the one on the right or bottom).
//  i.e. which cell requres less health to travel to
//  for this cell is (one which holds the princess):
//  val = min of dp[i+1][j] and dp[i][j+1] (min of bottom and right).
//  so val = min(1,1) = 1;
//  Also we have to reduce the health required to stay in the current cell.
//  val = val - dungeon[i][j] = 1 - (-5) = 6;
//  Now as i explained earlier:
//  dp[i][j] = max(1,val)   => if val is negetive that means we dont have to spend health on this cell so it should be kept minimum i.e. 1.
 
//  So we had to keep both values 1 as instead of max as for calculating the health for princess' cell we only need 1 health minimum. 
 
//  Now let's see for 2nd row 3rd column (one above the princess)
//  val = min(m,6) - 1;   (6 because the dp holds value 6 for princess' cell which was calculated earlier)
//  val = 5.
//  dp[1][2] = 5; So when we are at this cell we need health atleast 5. 
//  As we will gain 1 health and then move on to the princess's cell giving up  5  health and thus in this way we can calculate all the values.


class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int n = dungeon.length, m = dungeon[0].length;
        int[][] dp = new int[n+1][m+1];
        for(int i = 0; i <= n; i++)
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        dp[n-1][m] = dp[n][m-1] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int need = Math.min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = Math.max(need, 1);
            }
        }
        return dp[0][0];
    }
}