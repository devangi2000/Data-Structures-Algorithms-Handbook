// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Example 3:

// Input: s = "bb"
// Output: 2

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        int count = 0;
        int n = s.size();
        bool odd = false;
        for(int i=0; i<s.size(); i++) m[s[i]]++;
        for(auto a:m){
            if(a.second%2==0) count+= a.second;
            else{
                odd = true;
                count += a.second-1;
            }
        }
       return odd ? count + 1: count; 
    }
};

