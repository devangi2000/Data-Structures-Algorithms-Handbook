// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".
 

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.

class Solution {
public:
    string getString(string s){
        int count = 0, i = 0, j = s.size() - 1;
        string res = "";
        while(j >= 0){
            if(s[j] == '#'){
                count++; j--;
            }
            else{
                if(count == 0)
                    res += s[j--];
                else{
                    count--;
                    j--;
                }
            }
        }
        return res;
    }
    
    bool backspaceCompare(string s, string t) {
        return getString(s) == getString(t);
    }
};

// Stack
class Solution {
    public Stack<Character> getString(String s){
        Stack<Character> st = new Stack<>();
        for(Character c : s.toCharArray()){
            if(c != '#')
                st.push(c);
            else if(!st.empty()) st.pop();
        }
        return st;
    }
    
    public boolean backspaceCompare(String s, String t) {
        return getString(s).equals(getString(t));
    }
}