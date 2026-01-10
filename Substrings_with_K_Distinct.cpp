#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int countSubstr(string& s, int k) {
                
                int n = s.size();
                // Lambda function to count substrings with at least k distinct characters
                auto f = [&] (int k) -> int {
                        int ans = 0;
                        vector<int> m(26, 0); // Frequency map for characters a-z
                        int cnt = 0; // Count of distinct characters in current window
                        
                        // Sliding window approach
                        for (int i = 0, j = 0; i < n; i++) {
                                // Expand window: add character at position i
                                if (m[s[i] - 'a'] == 0) cnt++; // New distinct character
                                m[s[i] - 'a']++;
                                
                                // Shrink window from left while we have at least k distinct characters
                                while (cnt >= k) {
                                        ans += n - i; // All substrings ending at i with j as left bound
                                        m[s[j] - 'a']--;
                                        if (m[s[j] - 'a'] == 0) cnt--; // Character removed from window
                                        j++;
                                }
                        }
                        return ans;
                };
                // Return substrings with exactly k distinct characters
                return f(k) - f(k + 1);
        }
};