// https://practice.geeksforgeeks.org/problems/power-set4302/1
// Given a string S find all possible subsequences of the string in lexicographically-sorted order.

// Example 1:

// Input : str = "abc"
// Output: a ab abc ac b bc c
// Explanation : There are 7 substrings that 
// can be formed from abc.
// Example 2:

// Input: str = "aa"
// Output: a a aa
// Explanation : There are 3 substrings that 
// can be formed from aa.

// Expected Time Complexity: O(2n) where n is the length of the string
// Expected Space Complexity : O(n * 2n) 

// Constraints: 
// 1 <= Length of string <= 16
  

  // first method
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> result;
		    int n = s.size();
		    for(int i = 1; i < (1 << n); i++){
		        string res = "";
		        int temp = i, j = 0;
		        while(temp){
		            if(temp & 1)
		                res += s[j];
		            j++;
		            temp >>= 1;
		        }
		        if(!res.empty())
		            result.push_back(res);
		    }
		    sort(result.begin(), result.end());
		    return result;
		}
};

// second method

class Solution{
	public:
	    vector<string> ans;
	    
	    void solve(string s, int start, string curr){
	        if(start == s.size()){
	            if(curr != "")
	                ans.push_back(curr);
	           return;
	        }
	        solve(s, start+1, curr);
	        solve(s, start+1, curr+s[start]);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    solve(s, 0, "");
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
