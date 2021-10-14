// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
// Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer,
//  and it is guaranteed an answer exists.

// Example 1:
// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]
// Example 2:
// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]

// Constraints:
// 1 <= barcodes.length <= 10000
// 1 <= barcodes[i] <= 10000

class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int code : barcodes) 
            mp.put(code, mp.getOrDefault(code, 0) + 1);
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(mp.entrySet());
        Collections.sort(list, Map.Entry.<Integer, Integer>comparingByValue().reversed());
        int l = barcodes.length, i = 0;
        int[] res = new int[l];
        for(Map.Entry<Integer, Integer> e : list){
            int pos = e.getValue();
            while(pos-- > 0){
                res[i] = e.getKey();
                i += 2;
                if(i >= barcodes.length) i = 1;
            }
        }
        return res;
    }
}
