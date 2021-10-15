// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose any two stones and smash them together.
// Suppose the stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the smallest possible weight of the left stone. If there are no stones left, return 0.

// Example 1:

// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation:
// We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
// we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
// we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
// we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
// Example 2:

// Input: stones = [31,26,33,21,40]
// Output: 5
// Example 3:

// Input: stones = [1,2]
// Output: 1


// METHOD 1
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0, sum2 = 0, n = stones.size();
        sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<bool>> dp(n+1, vector<bool>(sum/2 + 1, 0));
        for(int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= sum/2; ++j){
                if(dp[i-1][j] or (j >= stones[i-1] && dp[i-1][j-stones[i-1]])){
                    dp[i][j] = 1;
                    sum2 = max(j, sum2);
                }
            }
        }
        return sum - (2*sum2);
    }
};


// METHOD 2
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(j==0) 
                    dp[i][j] = true;
                else if(i==0) 
                    dp[i][j] = false;
                else if(stones[i-1] > j) 
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
            }
        }
        
        int diff = INT_MAX;
        for(int i=0; i<=sum/2; i++){
            int first = i;
            int second = sum-i;
            if(dp[n][i])
            {
                diff = min(diff, abs(second-first));
            }
        }
        return diff;
    }
};
