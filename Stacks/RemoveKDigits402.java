Given string num representing a non-negative integer num, and an integer k, return the smallest 
// possible integer after removing k digits from num.
// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:
// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// Constraints:
// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        int n = num.length();
        for(int i = 0; i < n; i++){
            while(!st.isEmpty() && k > 0 && st.peek() > num.charAt(i)){
                st.pop(); k--;
            }
            if(!st.isEmpty() || num.charAt(i) != '0')
                st.push(num.charAt(i));
        }
        while(!st.isEmpty() && k > 0){
            st.pop(); k--;
        }
        if(st.isEmpty()) return "0";
        StringBuilder res = new StringBuilder();
        while(!st.isEmpty()){
            res.append(st.pop());
        }
        res.reverse();
        return res.toString();
    }
}

