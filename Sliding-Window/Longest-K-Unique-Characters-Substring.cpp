// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#

// Given a string you need to print the size of the longest possible substring
// that has exactly K unique characters. If there is no possible substring then print -1.

// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output: 7
// Explanation: "cbebebe" is the longest 
// substring with K distinct characters.
// Example 2:

// Input: 
// S = "aaaa", K = 2
// Output: -1
// Explanation: There's no substring with K
// distinct characters.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |S| ≤ 105
// 1 ≤ K ≤ 105

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int n = s.size(), start = 0, end = 0, ans = INT_MIN;
    if(n == 0 || n == 1) return n;
    unordered_map<char, int> m;
    while(end <= n){
        if(m.size()<k){
            m[s[end++]]++;
        }
        else if(m.size()==k){
            ans = max(ans, end - start);
            m[s[end++]]++;
            }
        else if(m.size() > k){
            while(m.size() > 0 and m.size()>k){
                m[s[start]]--;
                if(m[s[start]] == 0) m.erase(s[start]);
                start++;
            }
        }
      }
      return ans > INT_MIN ? ans : -1;
    }
  };
