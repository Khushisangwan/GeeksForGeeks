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
        // code here
        int n = arr.size();
        vector<int> prefix(n,0);
        sort(arr.begin(), arr.end());
        partial_sum(arr.begin(), arr.end(),prefix.begin());
        int ans = INT_MAX;
        int prev = 0;
        for(int i = 0;i<n;i++)
        {
        int index = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();
           if(i>0 && (arr[i] != arr[i-1]))
               prev = prefix[i-1];
            int x = prev + (prefix[n-1] - prefix[index-1]) - (n-index) *(arr[i] + k);
             ans = min(ans, x);
        }
        return ans;
    }
};