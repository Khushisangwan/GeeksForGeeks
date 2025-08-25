#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize median after doing k addition operation
// Approach: Sort the array and use a greedy approach to increment the median

// Steps:
// 1. Sort the array to easily access the median and its neighbors
// 2. Use a while loop to increment the median and its neighbors until k operations are exhausted
// 3. If the median can be increased to the next distinct value, do so and update k accordingly
// 4. If k is not enough to reach the next distinct value, distribute the remaining k evenly among the current median and its neighbors
// 5. Return the new median value

// Time Complexity: O(n log n) due to sorting the array.
// Space Complexity: O(1) as we are using only a few extra variables.

class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        int n = arr.size(), cur = (n-1)/2;
        sort(arr.begin(), arr.end());
        
        if(n%2 == 0 && arr[cur+1]-arr[cur] >= k) return (arr[cur+1] + arr[cur] + k)/2;
        
        int len = 1;
        while(k) {
            while(cur < n-1 && arr[cur] == arr[cur+1]) cur++, len++;
            
            if(cur == n-1)  return arr[cur] + k / len;
            int diff = arr[cur+1] - arr[cur];
            
            if(k >= diff * len) cur++, k -= diff * len, len++;
            else return arr[cur] + k / len;
        }
        
        return arr[cur];
    }
};