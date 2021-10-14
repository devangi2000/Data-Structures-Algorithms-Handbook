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

class Solution
{
    public:
    static bool cmp(Item a, Item b){
        return (double)a.value/(double)a.weight > (double)a.value/(double)a.weight;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, cmp);
        double cursum = 0.0;
        for(int i=0; i<n; i++){
            if(W >= arr[i].weight){
                cursum += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                cursum += arr[i].value*((double)W/arr[i].weight);
                break;
            }
        }
        return cursum;
    }
        
};
