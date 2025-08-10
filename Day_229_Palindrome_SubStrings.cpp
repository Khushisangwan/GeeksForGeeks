
#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Count the number of palindromic substrings in a given string
// Approach: Use dynamic programming to check for palindromic substrings
// Steps:
// 1. Initialize a 2D vector to keep track of palindromic substrings.
// 2. Mark single characters as palindromes.
// 3. Check for two-character palindromes.
// 4. Use a gap-based approach to check for longer palindromic substrings.
// 5. Count the total number of palindromic substrings found.
// Time Complexity: O(n^2), where n is the length of the string, as we check each substring.
// Space Complexity: O(n^2), for the 2D vector used to store palindrome checks.
class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        int res = 0;
    
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                res++;
            }
        }
    
        for (int gap = 2; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
      
        return res;
    }
};