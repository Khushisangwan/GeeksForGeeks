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
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size(), mx = 0;
        vector<vector<int>> dp(n);
        vector<int> ans;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++){
            dp[i] = {arr[i]};
            for(int j = 0; j < i; j++) {
                if (1 + dp[j].size() >= dp[i].size() and arr[i] % arr[j] == 0) {
                    vector<int> temp = dp[i];
                    temp.pop_back();
                    if (1 + dp[j].size() ==  dp[i].size()) {
                        temp = dp[j];
                        temp.push_back(arr[i]);
                        dp[i] = max(dp[i], temp);
                    } 
                    else {
                        dp[i] = dp[j];
                        dp[i].push_back(arr[i]);
                    }
                }
            }
            mx = max(mx, (int) dp[i].size());
        }
        
        for (int i = 0; i < n; i++){
            if(dp[i].size() == mx) {
                if(ans.empty())
                    ans = dp[i];
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};