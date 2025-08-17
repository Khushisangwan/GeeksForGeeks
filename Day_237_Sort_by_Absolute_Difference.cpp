#include <bits/stdc++.h>
using namespace std;
// Problem: Rearrange the elements of an array based on their absolute difference from a given integer x.
// Approach is to use a multimap to store the absolute differences and their corresponding elements, then sort them based on the differences.
// Steps:
// 1. Create a multimap to store pairs of absolute difference and the corresponding element.
// 2. Iterate through the array and insert each element into the multimap with its absolute difference from x.
// 3. Iterate through the multimap and fill the original array with the sorted elements.

// Time Complexity: O(n log n) due to the multimap operations, where n is the number of elements in the array.
// Space Complexity: O(n) for storing the elements in the multimap.
class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        multimap<int,int>m;
        for(auto i:arr)
        {
            m.insert({abs(i-x),i});
        }
        int i=0;
        for(auto &j:m){
            arr[i++]=j.second;
        }
    }
};