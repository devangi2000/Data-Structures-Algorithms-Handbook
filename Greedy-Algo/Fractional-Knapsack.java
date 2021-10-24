// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

// Example 1:

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack. 
// Example 2:

// Input:
// N = 2, W = 50
// values[] = {60,100}
// weight[] = {10,20}
// Output:
// 160.00
// Explanation:
// Total maximum value of item
// we can have is 160.00 from the given
// capacity of sack.
 
// Expected Time Complexity : O(NlogN)
// Expected Auxilliary Space: O(1)


// Constraints:
// 1 <= N <= 105
// 1 <= W <= 105

// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

// Example 1:

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack. 
// Example 2:

// Input:
// N = 2, W = 50
// values[] = {60,100}
// weight[] = {10,20}
// Output:
// 160.00
// Explanation:
// Total maximum value of item
// we can have is 160.00 from the given
// capacity of sack.
 
// Expected Time Complexity : O(NlogN)
// Expected Auxilliary Space: O(1)


// Constraints:
// 1 <= N <= 105
// 1 <= W <= 105

/*
class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}
*/

class Solution
{
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        Arrays.sort(arr,(a,b)->((b.value/b.weight)-(a.value/a.weight)));
        double total = 0.0;
        for(int i = 0; i < n; i++){
            if(W >= arr[i].weight){
                W -= arr[i].weight;
                total += arr[i].value;
            }
            else{
                total += arr[i].value * ((double)W / (double)arr[i].weight);
                break;
            }
        }
        return total;
    }
}