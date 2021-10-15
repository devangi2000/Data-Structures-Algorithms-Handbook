// Given a string s, return the longest palindromic substring in s. 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), longestStart = 0, longestPalindrome = 1;
        if(n <= 1)
            return s;
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for(int i = n-1; i>=0; i--){
            for(int dist = 1; dist < n-i; dist++){
                int j = dist + i;
                dp[i][j] = (dist==1) ? s[i] == s[j] : (s[i] == s[j] and dp[i+1][j-1]);
                if(dp[i][j] and j - i + 1 > longestPalindrome){
                    longestStart = i;
                    longestPalindrome = j - i + 1;
                }
            }
        }
        return s.substr(longestStart, longestPalindrome);
    }
};


// Easiest to understand

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, n = s.size(), end = 0;
        if(n <= 1) return s;
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        int longestPalindromeLength = 1, longestPalindromeStart = 0;
        for(int start = n - 1; start >= 0; start--){
            for(int end = start + 1; end < n; end++){
                if(s[start]==s[end]){
                    if(end - start == 1 or dp[start + 1][end - 1]){
                        dp[start][end] = true;
                        if(longestPalindromeLength < end - start + 1){
                            longestPalindromeLength = end - start + 1;
                            longestPalindromeStart = start;
                        }
                    }
                }
            }
        }
        return s.substr(longestPalindromeStart, longestPalindromeLength);
    }
};



// DP Approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        int leni=1,lenj=1,i,j;
        int dp[n+1][n+1];
        for(i=0;i<n+1;i++)
        {
            dp[0][i]=1;
            dp[1][i]=1;
        }
        for(i=2;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                if(s[j-1]==s[j-i]&&dp[i-2][j-1]==1)
                    dp[i][j]=1,leni=i,lenj=j;
                else
                    dp[i][j]=0;
            }
        }
        for(i=lenj-leni;i<lenj;i++)
            res.push_back(s[i]);
        
        return res;
    }
};

// METHOD 2:
/*
class Solution {
public:
    string longestPalindrome(string s) {
       if(s.size() <= 1) return s;
        int max_len = 1;
        int n = s.size();
        int start = 0, end = 0;
        
        // Odd length
        for(int i=0; i<n-1; i++){
            int l = i, r = i;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--; r++;
                } else break;
            }
            int len = r - l - 1;
            if(len > max_len){
                max_len = len;
                start = l + 1;
                end = r - 1;
            }
    }
        
         // Even length
        for(int i=0; i<n-1; i++){
            int l = i, r = i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--; r++;
                } else break;
            }
            int len = r - l - 1;
            if(len > max_len){
                max_len = len;
                start = l + 1;
                end = r - 1;
            }
    }
        
        return s.substr(start, max_len);
}
};

*/
