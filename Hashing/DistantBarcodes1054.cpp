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
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> m;
        for(auto code : barcodes)
            m[code]++;
        set<pair<int, int>> s;
        for(auto it = m.begin(); it != m.end(); ++it)
            s.insert({it->second, it->first});
        int pos = 0;
        for(auto it = s.rbegin(); it != s.rend(); ++it){
            for(auto count = 0; count < it->first; ++count, pos += 2){
                if(pos >= barcodes.size()) pos = 1;
                barcodes[pos] = it->second;
            }
        }
        return barcodes;
    }
};
