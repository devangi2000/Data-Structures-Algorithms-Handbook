// Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.
// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// Constraints:
// 1 <= s.length <= 5 * 105
// s consists of English letters and digits.

class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        for(char c : s.toCharArray())
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        pq.addAll(mp.entrySet());
        
        StringBuilder sb = new StringBuilder();
        while(!pq.isEmpty()){
            Map.Entry e = pq.poll();
            for(int i = 0; i < (int)e.getValue(); i++)
                sb.append(e.getKey());
        }
        return sb.toString();
    }
}
