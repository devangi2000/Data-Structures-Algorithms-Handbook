// Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.


// Example 1:

// Input:
// N = 2
// start[] = {2, 1}
// end[] = {2, 2}
// Output: 
// 1
// Explanation:
// A person can perform only one of the
// given activities.
// Example 2:

// Input:
// N = 4
// start[] = {1, 3, 2, 5}
// end[] = {2, 4, 3, 6}
// Output: 
// 3
// Explanation:
// A person can perform activities 1, 2
// and 4.

// Your Task :
// You don't need to read input or print anything. Your task is to complete the function activityselection() which takes array start[ ], array end[ ] and integer N as input parameters and returns the maximum number of activities that can be done.


// Expected Time Complexity : O(N * Log(N))
// Expected Auxilliary Space : O(N)

// Constraints:
// 1 ≤ N ≤ 2*105
// 1 ≤ start[i] ≤ end[i] ≤ 109

class Solution
{
    public:
    static bool compare(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n) {
        // create a pair of starting, ending day
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = make_pair(start[i], end[i]);
        
        // sort it in ascending order of ending day: we want to complete activity which end at the earliest
        sort(arr.begin(), arr.end(), compare);
        
        int count = 1; // pick the first activity
        int ft = arr[0].second; // finishing time of first activity
        
        for(int i = 1; i < n; i++) {
            // take current activity if its starting time > finishing time of earlier chosen activity
            if(arr[i].first > ft) {
                ft = arr[i].second;
                count++;
            }
        }
        return count;
    }
};
