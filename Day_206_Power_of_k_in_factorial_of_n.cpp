#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum power of k in the factorial of n
// Approach: Count the prime factors of k and their frequencies, then count how many times each prime factor can
//           divide n! using Legendre's formula.

// Steps:
// 1. Sieve of Eratosthenes to find all primes up to n.
// 2. Factor k into its prime factors and their frequencies.
// 3. For each prime factor, use Legendre's formula to count how many times it divides n!.
// 4. Divide the count by the frequency of the prime factor in k to get the maximum power.
// 5. Return the minimum of these values as the answer.

// Time Complexity: O(n log log n + log k) for the sieve and factorization, plus O(log n) for counting prime factors.
// Space Complexity: O(n) for the sieve and O(log k) for storing prime factors.

class Solution {
  public:
    int maxKPower(int n, int k) {
        vector<bool> isPrime(n + 1, true);
        unordered_map<int, int> primesforK;
        
        int ans = 1e9;
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= k; i++) {
            if (!isPrime[i]) continue;
            int expo = 0;
            while (k % i == 0) {
                k /= i;
                expo++;
            }
            if (expo > 0)
                primesforK[i] = expo;
        }

        for (auto& p : primesforK) {
            int prime = p.first;
            int freq = p.second;
            int cnt = 0;
            for (long long power = prime; power <= n; power *= prime)
                cnt += n / power;
            ans = min(ans, cnt / freq);
        }
        return ans;
    }
};