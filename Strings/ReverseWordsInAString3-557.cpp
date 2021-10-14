// Given a string s, reverse the order of characters in each word within a sentence while still preserving
//  whitespace and initial word order.

// Example 1:
// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:
// Input: s = "God Ding"
// Output: "doG gniD" 

// Constraints:
// 1 <= s.length <= 5 * 104
// s contains printable ASCII characters.
// s does not contain any leading or trailing spaces.
// There is at least one word in s.
// All the words in s are separated by a single space.

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                int j = i;
                for(; j < s.length() and s[j] != ' '; j++){}
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        return s;
    }
};