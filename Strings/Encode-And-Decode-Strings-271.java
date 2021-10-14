// Design an algorithm to encode a list of strings to a string. The encoded string is then sent 
// over the network and is decoded back to the original list of strings.

// Please implement encode and decode

// Example
// Example1

// Input: ["lint","code","love","you"]
// Output: ["lint","code","love","you"]
// Explanation:
// One possible encode method is: "lint:;code:;love:;you"
// Example2

// Input: ["we", "say", ":", "yes"]
// Output: ["we", "say", ":", "yes"]
// Explanation:
// One possible encode method is: "we:;say:;:::;yes"
// Tags
// Company
// Google

public class Solution {
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    public String encode(List<String> strs) {
        if(strs == null || strs.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        for(String str : strs){
            int len = (str == null) ? 0 : str.length();
            sb.append(len);
            sb.append('#');
            sb.append(str);
        }
        return sb.toString();
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    public List<String> decode(String str) {
        List<String> result = new ArrayList<String>();
        if(str == null || str.length() == 0) return result;
        int i = 0;
        while(i < str.length()){
            int len = 0;
            while(i < str.length() && str.charAt(i) != '#'){
                len = len * 10 + Character.getNumericValue(str.charAt(i));
                i++;
            }
            String temp = str.substring(i + 1, i + len + 1);
            result.add(temp);
            i = i + len + 1;
        }
        return result;
    }
}