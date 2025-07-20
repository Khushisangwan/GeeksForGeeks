#include <iostream>
#include <cmath>
using namespace std;
// Problem Statement: Count the number of valid n-digit numbers that can be formed using digits not present in a given array `arr`.
// Approach: Use total possible n-digit numbers and subtract those formed using allowed digits, accounting for leading zero rules.

// Step-by-step Procedure:
// 1. Initialize a flag `zero` to check if 0 is in the restricted digit array `arr`.
// 2. Calculate total number of n-digit numbers: total = 9 * 10^(n-1).
// 3. Calculate count of n-digit numbers formed using only allowed digits: nott = (10 - arr.size())^n.
// 4. If 0 is not in the restricted digits, subtract numbers starting with zero: nott -= (10 - arr.size())^(n-1).
// 5. Subtract nott from total to get final answer: total - nott.

// Time Complexity: O(1) — constant-time computation using mathematical operations.
// Space Complexity: O(1) — only a few variables used.

class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        bool zero = 0;
        for(auto it: arr)
            if(it == 0) zero = 1;
        
        int total = 9 * pow(10, n - 1);
        int nott = pow(10 - arr.size(), n);
        
        if(zero == 0)
            nott -= pow(10 - arr.size(), n - 1);
            
        return total - nott;
    }
};
