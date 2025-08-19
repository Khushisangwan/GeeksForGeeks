#include <bits/stdc++.h>
using namespace std;

// Problem: Find the farthest smaller element to the right for each element in an array.
// Approach: Sort the elements with their indices, then iterate to find the farthest smaller element.

// Steps:
// 1. Create a vector of pairs to store each element with its index.
// 2. Sort the vector based on the element values.
// 3. Initialize an answer vector with -1.
// 4. Iterate through the sorted vector and keep track of the maximum index seen so far.
// 5. For each element, if the maximum index seen so far is greater than the current index, update the answer for that index.
// 6. Return the answer vector.

// Time Complexity: O(n log n) due to sorting, where n is the number of elements.
// Space Complexity: O(n) for storing the pairs and the answer vector.

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> tmp(n);
        for(int i = 0; i < n; i++) tmp[i] = {arr[i], i};
        sort(tmp.begin(), tmp.end());
        vector<int> ans(n, -1);
        for(int i = 0, m = -1; i < n; i++) {
            if(m > tmp[i].second) ans[tmp[i].second] = m;
            m = max(m, tmp[i].second);
        }
        return ans;
    }
};