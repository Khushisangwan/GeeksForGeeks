#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestCommonSum(vector<int> &a1, vector<int> &a2) {
                // Get the size of the input arrays
                int n = a1.size();
                // Map to store the first occurrence of each prefix sum difference
                unordered_map<int, int> mpp;
                int sum = 0;    // To store the running sum of differences
                int maxi = 0;   // To store the maximum length found
                
                // Initialize the map with sum 0 at index -1
                mpp[0] = -1;
                
                // Traverse both arrays
                for (int i = 0; i < n; i++) {
                        // Update the running sum with the difference at current index
                        sum += (a1[i] - a2[i]);
                        // If this sum has been seen before, update the maximum length
                        if (mpp.find(sum) != mpp.end()) {
                                maxi = max(maxi, i - mpp[sum]);
                        } else {
                                // Otherwise, store the index of the first occurrence of this sum
                                mpp[sum] = i;
                        }
                }
                
                // Return the maximum length of subarray with equal sum in both arrays
                return maxi;
        }
};