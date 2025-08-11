#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Find the maximum sum of non-overlapping odd-length palindromes in a given string
// Approach: Use Manacher's algorithm to find all odd-length palindromes and calculate the maximum sum of non-overlapping ones.
//// Steps:
// 1. Use Manacher's algorithm to find the radius of odd-length palindromes centered at each character.
// 2. Create two arrays to store the best palindrome lengths ending and starting at each index.
// 3. Iterate through the string to fill these arrays with the maximum lengths of palindromes.
// 4. Use a two-pointer technique to find the maximum sum of non-overlapping palindromes.
// Time Complexity: O(n), where n is the length of the string, as we process each character a constant number of times.
// Space Complexity: O(n), for the arrays used to store palindrome lengths.
class Solution {
  public:
    int maxSum(string &s) {
        // code here
        int n = (int)s.size();
        if (n < 2) return 0;

        vector<int> rad(n); 
        for (int i = 0, L = 0, R = -1; i < n; ++i) {
            int k = (i > R) ? 1 : min(rad[L + R - i], R - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            rad[i] = k;
            if (i + k - 1 > R) { 
                L = i - k + 1;
                R = i + k - 1;
            }
        }

        vector<int> bestEnd(n, 0), bestStart(n, 0);
        for (int c = 0; c < n; ++c) {
            int len = 2 * rad[c] - 1;
            int l = c - rad[c] + 1;      
            int r = c + rad[c] - 1;
            bestEnd[r] = max(bestEnd[r] , len);
            bestStart[l] = max(bestStart[l] , len);
        }

        for (int i = n - 2; i >= 0; --i)
            bestEnd[i]   = max(bestEnd[i]  , bestEnd[i + 1] - 2);
            
        for (int i = 1; i < n; ++i)
            bestStart[i] = max(bestStart[i], bestStart[i - 1] - 2);

        int bestLeft = 0, ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            bestLeft = max(bestLeft, bestEnd[i]);
            ans  = max(ans, bestLeft + bestStart[i + 1]);
        }
        
        return ans;
    }
}; 
