#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string largestSwap(string &s) {
                // Get the length of the string
                int n = s.size();
                
                // Create a copy of the string and sort it in descending order
                // This gives us the largest possible arrangement
                string t = s;
                sort(t.begin(), t.end(), greater<int>());
                
                // Find the first position where original string differs from sorted string
                int d = -1;
                for(int i = 0; i < n; i++){
                        if(t[i] != s[i]) {
                                d = i;
                                break;
                        }
                }
                
                // If no difference found, string is already in largest form
                if (d == -1) return s;
                
                // Find the rightmost occurrence of the target digit to maximize the swap
                // We search from right to left to get the digit at the rightmost position
                for(int i = n - 1; i >= 0; i--){
                        if(t[d] == s[i]){
                                // Swap the digits to get the largest number
                                swap(s[d], s[i]);
                                break;
                        }
                }
                
                return s;
        }
};