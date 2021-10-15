// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

// Example 1:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Example 3:

// Input: s1 = "", s2 = "", s3 = ""
// Output: true

class Solution {
public:
    int dp[1001][1001];
    bool solve(string s1, string s2, string s3, int l1, int l2, int l3){
        if(l3==0) return 1;
        if(dp[l1][l2]!=-1) return dp[l1][l2];
        
        int a=0, b=0;
        if(l1>=1 and s1[l1-1]==s3[l3-1]) a = solve(s1, s2, s3, l1-1, l2, l3-1);
        if(l2>=1 and s2[l2-1]==s3[l3-1]) b = solve(s1, s2, s3, l1, l2-1, l3-1);
        return dp[l1][l2] = a or b;        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(); int l2=s2.size(); int l3=s3.size();
        if(l1+l2!=l3) return 0;
        dp[l1][l2];
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, l1, l2, l3);        
    }
};


// OR

int Solution::isInterleave(string A, string B, string C) {
    int n = A.size(), m = B.size(), s = C.size();
    if(n + m != s) return 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <=n; i++){
        if(A[i-1] == C[i-1])
            dp[i][0] = 1;
        else break;
    }
    for(int j = 1; j <= m; j++){
        if(B[j-1] == C[j-1])
            dp[0][j] = 1;
        else break;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i-1] == C[i+j-1] || B[j-1] == C[i+j-1])
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][m];
}
