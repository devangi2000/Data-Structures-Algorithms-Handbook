// 204. Count Primes

// Count the number of prime numbers less than a non-negative number, n. 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
  

// This uses sieve of eratosthenes for optimization
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0;
        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;
        for(int i = 2; i*i < n; i++){
            if(primes[i]){
                for(int j = i; j*i < n; j++){
                    primes[i*j] = 0;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++)
            if(primes[i]) 
                count++;
        return count;
    }
};