// Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


// Example 1:

// Input:
// N = 4
// Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60
// Explanation:
// Job1 and Job3 can be done with
// maximum profit of 60 (20+40).
// Example 2:

// Input:
// N = 5
// Jobs = {(1,2,100),(2,1,19),(3,2,27),
//         (4,1,25),(5,1,15)}
// Output:
// 2 127
// Explanation:
// 2 jobs can be done with
// maximum profit of 127 (100+27).

// Your Task :
// You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(N)


// Constraints:
// 1 <= N <= 105
// 1 <= Deadline <= 100
// 1 <= Profit <= 500


class Solution
{
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
        Arrays.sort(arr, (a, b) -> (b.profit - a.profit));
        int jobs = 0, total = 0, maxi = arr[0].deadline;
        for(int i = 0; i < n; i++)
            maxi = Math.max(arr[i].deadline, maxi);
        int[] slots = new int[maxi + 1];
        Arrays.fill(slots, -1);
        for(int i =0; i < n; i++){
            for(int j = arr[i].deadline; j > 0; j--){
                if(slots[j] == -1){
                    jobs++;
                    total += arr[i].profit;
                    slots[j] = i;
                    break;
                }
            }
        }
        return new int[] {jobs, total};
    }