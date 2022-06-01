// Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
//  If no such two words exist, return 0.


// Example 1:

// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".
// Example 2:

// Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4
// Explanation: The two words can be "ab", "cd".
// Example 3:

// Input: words = ["a","aa","aaa","aaaa"]
// Output: 0
// Explanation: No such pair of words.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), i = 0, maxi = 0;
        vector<int> wordsInt(n, 0);
        for(auto word : words){
            int wordInt = 0;
            for(char c : word){
               wordInt |= 1 << (c - 'a');                
            }
            wordsInt[i++] = wordInt;
        }
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if((wordsInt[i] & wordsInt[j]) == 0)
                    maxi = words[i].length() * words[j].length() > maxi ? words[i].length() * words[j].length() : maxi;
            }
        }
        return maxi;
    }
};