// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's 
// price for the current day.
// The span of the stock's price today is defined as the maximum number of consecutive days (starting from 
// today and going backward) for which the stock price was less than or equal to today's price.
// For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock 
// spans would be [1,1,1,2,1,4,6].
// Implement the StockSpanner class:
// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.
// Example 1:
// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]
// Explanation
// StockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // return 1
// stockSpanner.next(80);  // return 1
// stockSpanner.next(60);  // return 1
// stockSpanner.next(70);  // return 2
// stockSpanner.next(60);  // return 1
// stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were 
// less than or equal to today's price.
// stockSpanner.next(85);  // return 6
//  Constraints:
// 1 <= price <= 105
// At most 104 calls will be made to next.

class StockSpanner {

    public StockSpanner() {
        
    }
    Stack<int[]> st = new Stack<>();
    public int next(int price) {
        int res = 1;
        while(!st.isEmpty() && st.peek()[0] <= price){ // If the current price is greater than stack peek.
            res += st.peek()[1];
            st.pop();
        }
        st.push(new int[] {price, res});
        return res;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */

/*
   Let's trace the algorithm together on [100, 80, 60, 70, 60, 75, 85]
   1. calling StockSpanner.next(100) should result in first element in our stack will be (100, 1) (s.size() == 1)
   2. calling StockSpanner.next(80) should result in second element in our stack will be (80, 1) (s.size() == 2)
   3. calling StockSpanner.next(60) should result in third element in our stack will be (60, 1) (s.size() == 3)
   4. Now on calling StockSpanner.next(70) we should add span of (60) + 1 {the current day}
   and remove it from stack (70, 2) (s.size() == 3)
   5. Now on calling StockSpanner.next(60) result in fourth element in our stack will be (60, 1) (s.size() == 4)
   6. Now on calling StockSpanner.next(75) we should add span of (60) and (70) + 1 {the current day}
   and remove it from stack : (75, 4) (s.size() == 3)
   7. Now on calling StockSpanner.next(85) we should add span of (75) and (80) + 1 {the current day}
   and remove it from stack : (85, 6) (s.size() == 2)
   */

