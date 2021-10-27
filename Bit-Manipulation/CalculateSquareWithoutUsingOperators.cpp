// Simple solution to calculate square without
// using * and pow()

// If n is even, it can be written as
//   n = 2*x 
//   n2 = (2*x)2 = 4*x2
// If n is odd, it can be written as 
//   n = 2*x + 1
//   n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
#include <iostream>
using namespace std;

int square(int n)
{
	if(n == 0)
      return 0;
  	if(n < 0)
      n = -n;
  	int x = n >> 1;
  	if(n & 1)
      return (square(x) << 2) + (square(x) << 2) + 1;
    else return square(x) << 2;
}

// Driver code
int main()
{
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n)
			<< endl;
	return 0;
}