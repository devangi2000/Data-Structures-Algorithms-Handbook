// With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
// word contains the first letter of puzzle.
// For each letter in word, that letter is in puzzle.
// For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
// invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
// Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].
 

// Example 1:

// Input: words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
// Output: [1,1,3,2,4,0]
// Explanation: 
// 1 valid word for "aboveyz" : "aaaa" 
// 1 valid word for "abrodyz" : "aaaa"
// 3 valid words for "abslute" : "aaaa", "asas", "able"
// 2 valid words for "absoryz" : "aaaa", "asas"
// 4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
// There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
// Example 2:

// Input: words = ["apple","pleas","please"], puzzles = ["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]
// Output: [0,1,3,2,0]
 

// Constraints:

// 1 <= words.length <= 105
// 4 <= words[i].length <= 50
// 1 <= puzzles.length <= 104
// puzzles[i].length == 7
// words[i] and puzzles[i] consist of lowercase English letters.
// Each puzzles[i] does not contain repeated characters.


class Solution {
    private int bitmask(String word) {
        // Build a bitmask of chars to represent each word
        // the builtin std::bitset also works
        int mask = 0;
        for (char letter : word.toCharArray()) {
            mask |= 1 << (letter - 'a');
        }
        return mask;
    }

    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> wordCount = new HashMap<>(); // a vector instead of unordered_map also works
        for (String word : words) {
            int mask = bitmask(word);
            wordCount.put(mask, wordCount.getOrDefault(mask, 0) + 1);
        }
        List<Integer> result = new ArrayList<>();
        for (String puzzle : puzzles) {
            int first = 1 << (puzzle.charAt(0) - 'a');
            int count = wordCount.getOrDefault(first, 0);

            // Make bitmask but ignore the first character since it must always be there.
            int mask = bitmask(puzzle.substring(1));

            // iterate over the submask
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                count += wordCount.getOrDefault(submask | first, 0); // add first character
            }
            result.add(count);
        }
        return result;
    }
};