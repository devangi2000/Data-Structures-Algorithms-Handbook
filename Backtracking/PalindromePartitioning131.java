// Given a string s, partition s such that every substring of the partition is a palindrome. 
// Return all possible palindrome partitioning of s.
// A palindrome string is a string that reads the same backward as forward. 

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:
// Input: s = "a"
// Output: [["a"]]
 
// Constraints:
// 1 <= s.length <= 16
// s contains only lowercase English letters.

class Solution {
    List<List<String>> ans = new ArrayList<>();
    
    public void solve(String s, List<String> path, int start){
        if(start >= s.length()){
            ans.add(new ArrayList(path));
            return;
        }
        for(int i = start; i < s.length(); i++){
            String str = s.substring(start, i + 1);
            if(isPalindrome(str)){
                path.add(str);
                solve(s, path, i+1);
                path.remove(path.size() - 1);
            }
        }
    }
    
    public List<List<String>> partition(String s) {
        solve(s, new ArrayList<>(), 0);
        return ans;
    }
    
    public boolean isPalindrome(String s){
        int start = 0, end = s.length() - 1;
        while(start <= end){
            if(s.charAt(start) != s.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;
    }
}