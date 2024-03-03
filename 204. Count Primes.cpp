class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // There are no prime numbers less than 2
        
        vector<bool> isPrime(n, true); // Initialize all numbers as prime
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
        
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) { // If i is prime
                // Mark all multiples of i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Count the number of primes
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) ++count;
        }
        
        return count;
    }
};
/*This implementation has a time complexity of O(n log log n) and a space complexity of O(n).*/
