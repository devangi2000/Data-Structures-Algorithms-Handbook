// https://www.hackerrank.com/challenges/board-cutting/problem

// Alice gives Bob a board composed of  wooden squares and asks him to find the minimum cost of breaking the board back down into its individual squares. To break the board down, Bob must make cuts along its horizontal and vertical lines.

// To reduce the board to squares, Bob makes horizontal and vertical cuts across the entire board. Each cut has a given cost,  or  for each cut along a row or column across one board, so the cost of a cut must be multiplied by the number of segments it crosses. The cost of cutting the whole board down into  squares is the sum of the costs of each successive cut.

// Can you help Bob find the minimum cost? The number may be large, so print the value modulo .

// For example, you start with a  board. There are two cuts to be made at a cost of  for the horizontal and  for the vertical. Your first cut is across  piece, the whole board. You choose to make the horizontal cut between rows  and  for a cost of . The second cuts are vertical through the two smaller boards created in step  between columns  and . Their cost is . The total cost is  and .

// Function Description

// Complete the boardCutting function in the editor below. It should return an integer.

// boardCutting has the following parameter(s):

// cost_x: an array of integers, the costs of vertical cuts
// cost_y: an array of integers, the costs of horizontal cuts
// Input Format

// The first line contains an integer , the number of queries.

// The following  sets of lines are as follows:

// The first line has two positive space-separated integers  and , the number of rows and columns in the board.
// The second line contains  space-separated integers cost_y[i], the cost of a horizontal cut between rows  and  of one board.
// The third line contains  space-separated integers cost_x[j], the cost of a vertical cut between columns  and  of one board.
// Constraints

// Output Format

// For each of the  queries, find the minimum cost () of cutting the board into  squares and print the value of .

// Sample Input 0

// 1
// 2 2
// 2
// 1
// Sample Output 0

// 4
// Explanation 0
// We have a  board, with cut costs  and . Our first cut is horizontal between  and , because that is the line with the highest cost (). Our second cut is vertical, at . Our first cut has a  of  because we are making a cut with cost  across  segment, the uncut board. The second cut also has a  of  but we are making a cut of cost  across  segments. Our answer is .

// Sample Input 1

// 1
// 6 4
// 2 1 3 1 4
// 4 1 2
// Sample Output 1

// 42
// Explanation 1
// Our sequence of cuts is: , , , , , ,  and .
// Cut 1: Horizontal with cost  across  segment. .
// Cut 2: Vertical with cost  across  segments. .
// Cut 3: Horizontal with cost  across  segments. .
// Cut 4: Horizontal with cost  across  segments. .
// Cut 5: Vertical with cost  across  segments. .
// Cut 6: Horizontal with cost  across  segments. .
// Cut 7: Horizontal with cost  across  segments. .
// Cut 8: Vertical with cost  across  segments. .


int boardCutting(vector<int> cost_y, vector<int> cost_x) {
    sort(cost_x.begin(), cost_x.end(), greater<int>());
    sort(cost_y.begin(), cost_y.end(), greater<int>());
    int ans = 0, m = cost_x.size(), n = cost_y.size(),
    h = 1, v = 1, i = 0, j = 0;
    while(i<m && j<n){
        if(cost_x[i] > cost_y[j]){
            ans += (cost_x[i] * v)%1000000007;
            h++;
            i++;
            }
        else{
            ans+= (cost_y[j]*h)%1000000007;
            v++;
            j++;
        }
    }
    while(i<m){
       ans += (cost_x[i] * v)%1000000007;
       i++; 
    }
    while(j<n){
       ans += (cost_y[j] * h)%1000000007;
       j++; 
    }
    return ans%1000000007;
}
