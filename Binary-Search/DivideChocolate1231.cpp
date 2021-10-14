// You have one chocolate bar that consists of some chunks. 
// Each chunk has its own sweetness given by the array sweetness.
// You're going to share this chocolate with K friends, so you need to cut K times to get K + 1 pieces,
//  each of which is made up of a series of small pieces.
// Being generous, you will eat the piece with the minimum total sweetness and give the other pieces
//  to your friends.
// Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.
// 0 <= K < sweetness.length <= 10^4
// 1 <= sweetness[i] <= 10^5
// Example
// Example 1:
// Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
// Output: 6
// Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
// Example 2:
// Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
// Output: 1
// Explanation: There is only one way to cut the bar into 9 pieces.
// Example 3:
// Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
// Output: 5
// Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]

class Solution {
public:
    /**
     * @param sweetness: an integer array
     * @param K: an integer
     * @return:  return the maximum total sweetness of the piece
     */
    int getCuts(vector<int> &sweetness, int k, int mid){
        int cuts = 0, sum = 0;
        for(int i : sweetness){
            sum += i;
            if(sum >= mid){
                ++cuts;
                sum = 0;
            }
        }
        return cuts;
    }

    int maximizeSweetness(vector<int> &sweetness, int k) {
        int low = 1, high = 0;
        for(auto a : sweetness)
            high += a;
        high = high / (k + 1);
        while(low < high){
            int mid = (high + low + 1) >> 1;
            int cuts = getCuts(sweetness, k, mid);
            if(cuts >= k+1)
                low = mid;
            else high = mid - 1;
        }
        return low;
    }
};

