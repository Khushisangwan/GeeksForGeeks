#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int i = 0, j = 0;
        int n = s1.length(), m = s2.length();

        string ans = "";
        int len = INT_MAX;

        // Forward pass: find a window containing s2 as a subsequence
        while (i < n) {
            // Match characters of s2 in s1
            if (s1[i] == s2[j]) j++;

            // When entire s2 is matched
            if (j == m) {
                int end = i;
                j = m - 1;

                // Backward pass: shrink the window from left
                while (i >= 0 && j >= 0) {
                    if (s1[i] == s2[j]) j--;
                    i--;
                }
                i++;

                // Update answer if current window is smaller
                if (end - i + 1 < len) {
                    len = end - i + 1;
                    ans = s1.substr(i, len);
                }

                // Reset j for next iteration
                j = 0;
            }
            i++;
        }

        return ans;
    }
};