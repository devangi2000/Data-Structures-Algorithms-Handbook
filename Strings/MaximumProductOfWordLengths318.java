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
    public int maxProduct(String[] words) {
        int n = words.length, maxi = 0, k = 0;
        int[] wordsInt = new int[n];
        Arrays.fill(wordsInt, 0);
        for(String word : words){
            int wordInt = 0;
            for(Character c : word.toCharArray())
                wordInt |= 1 << (c - 'a');
            wordsInt[k++] = wordInt;
        }
        for(int i = 0; i < n - 1; i++){
            for(int j = i+1; j < n; j++){
                if((wordsInt[i] & wordsInt[j]) == 0)
                    maxi = Math.max(words[i].length() * words[j].length(), maxi);
            }
        }
        return maxi;
    }
}