#include <bits/stdc++.h>
using namespace std;

// Problem: Largest Divisible Subset
// Approach to find the largest subset of an array where every pair of elements in the subset is divisible by each other.

// Steps:
// 1. Sort the array to ensure that we can build subsets in increasing order.
// 2. Use dynamic programming to build subsets where each element is divisible by the previous ones.
// 3. Maintain a vector of vectors to store the largest subset ending at each index.
// 4. Iterate through the array, checking for divisibility and updating the largest subset accordingly.
// 5. Finally, find the largest subset from the stored subsets.

// Time Complexity: O(n^2), where n is the size of the array.
// Space Complexity: O(n), for storing the subsets. 

class Solution {
    public:
        // Function to find the largest divisible subset
        vector<int> largestSubset(vector<int>& arr) {
                int n = arr.size(), mx = 0;
                vector<vector<int>> dp(n); // dp[i] stores the largest divisible subset ending at index i
                vector<int> ans; // To store the final answer
                sort(arr.begin(), arr.end()); // Step 1: Sort the array
                
                for(int i = 0; i < n; i++){
                        dp[i] = {arr[i]}; // Initialize each subset with the element itself
                        for(int j = 0; j < i; j++) {
                                // Check if arr[i] is divisible by arr[j] and if including arr[i] increases the subset size
                                if (1 + dp[j].size() >= dp[i].size() and arr[i] % arr[j] == 0) {
                                        vector<int> temp = dp[i];
                                        temp.pop_back();
                                        if (1 + dp[j].size() ==  dp[i].size()) {
                                                // If sizes are equal, take the lexicographically larger subset
                                                temp = dp[j];
                                                temp.push_back(arr[i]);
                                                dp[i] = max(dp[i], temp);
                                        } 
                                        else {
                                                // Otherwise, update dp[i] with the larger subset
                                                dp[i] = dp[j];
                                                dp[i].push_back(arr[i]);
                                        }
                                }
                        }
                        mx = max(mx, (int) dp[i].size()); // Update the maximum subset size found so far
                }
                
                // Find the subset(s) with the maximum size
                for (int i = 0; i < n; i++){
                        if(dp[i].size() == mx) {
                                if(ans.empty())
                                        ans = dp[i];
                                ans = max(ans, dp[i]); // Choose the lexicographically largest subset if there are multiple
                        }
                }
                return ans; // Return the largest divisible subset
        }
};