// https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
// Given an integer n, calculate the square of a number without using *, / and pow(). 

// Examples : 

// Input: n = 5
// Output: 25

// Input: 7
// Output: 49

// Input: n = 12
// Output: 144

// Linear TC
int square(int n)
{
    // handle negative input
    if (n < 0)
        n = -n;
 
    // Initialize result
    int res = n;
 
    // Add n to res n-1 times
    for (int i = 1; i < n; i++)
        res += n;
 
    return res;
}
// GFG

//  square(n) = 0 if n == 0
//   if n is even 
//      square(n) = 4*square(n/2) 
//   if n is odd
//      square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

// Examples
//   square(6) = 4*square(3)
//   square(3) = 4*(square(1)) + 4*1 + 1 = 9
//   square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49
// Log(N) TC
int square(int n)
{
    // Base case
    if (n == 0)
        return 0;
 
    // Handle negative number
    if (n < 0)
        n = -n;
 
    // Get floor(n/2) using right shift
    int x = n >> 1;
 
    // If n is odd
    if (n & 1)
        return ((square(x) << 2) + (x << 2) + 1);
    else // If n is even
        return (square(x) << 2);
}
