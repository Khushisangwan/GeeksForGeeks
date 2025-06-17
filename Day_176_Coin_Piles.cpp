#include <bits/stdc++.h>
using namespace std;
// Problem: Minimum Coins
// Contest: LeetCode - Weekly Contest 352
// URL: https://leetcode.com/contest/weekly-contest-352/problems/minimum-coins/
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// You are given an array arr of n integers, and an integer k.
// You can perform the following operation any number of times:
// Choose an index i (0 <= i < n) and add k to arr[i].

// Return the minimum number of coins needed to make all elements of arr equal.
// Note: The array is 0-indexed.

class Solution {
    public:
        int minimumCoins(vector<int>& arr, int k) {
                // Get the size of the array
                int n = arr.size();
                // Prefix sum array to store cumulative sums
                vector<int> prefix(n,0);
                // Sort the array to make processing easier
                sort(arr.begin(), arr.end());
                // Compute prefix sums
                partial_sum(arr.begin(), arr.end(), prefix.begin());
                int ans = INT_MAX; // Initialize answer to a large value
                int prev = 0;      // To store sum of elements before current index
                for(int i = 0; i < n; i++)
                {
                        // Find the first index where arr[index] > arr[i] + k
                        int index = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
                        // If current element is different from previous, update prev sum
                        if(i > 0 && (arr[i] != arr[i-1]))
                                prev = prefix[i-1];
                        // Calculate coins needed:
                        // prev: sum of elements before i (already equal or less)
                        // (prefix[n-1] - prefix[index-1]): sum of elements greater than arr[i]+k
                        // (n-index): number of such elements
                        // (arr[i] + k): target value for these elements
                        int x = prev + (prefix[n-1] - prefix[index-1]) - (n-index) * (arr[i] + k);
                        ans = min(ans, x); // Update answer if better
                }
                return ans;
        }
};