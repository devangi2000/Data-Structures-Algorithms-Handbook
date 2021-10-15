class Solution {
public:
  string shortestCommonSupersequence(string text1, string text2) {
        int s1=text1.size();
        int s2=text2.size();
        int dp[s1+1][s2+1];
        for(int i=0;i<=s1;i++){
            for(int j=0;j<=s2;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
# 		**\\\code of lcs**
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
# 		**\\print lcs**
        string ans="";
        int i=s1, j=s2;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    ans.push_back(text2[j-1]);
                    j--;
                }
                else{
                    ans.push_back(text1[i-1]);
                    i--;
                }   
            }
        }
# 		**\\\these 2 below loops to check if any one of the 
# \\\string is left with some  character then we also have to pushback them too**
        while(i>0){
            ans.push_back(text1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(text2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
