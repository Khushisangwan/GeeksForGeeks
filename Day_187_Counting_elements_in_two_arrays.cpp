#include<bits/stdc++.h>
using namespace std;
// Problem: Count elements less than or equal to each element in the first array from the second array
// Link: https://leetcode.com/problems/count-elements-in-two-arrays/description/
// Difficulty: Medium
// Time Complexity: O(nlogn + mlogm) where n is the size of the first array and m is the size of the second array

class Solution {
    public:
        // Function to count, for each element in 'a', the number of elements in 'b' less than or equal to it
        vector<int> countLessEq(vector<int>& a, vector<int>& b) {
                // Pair each element in 'a' with its original index to restore order after sorting
                vector<pair<int,int>> v;
                for(int i = 0 ; i < a.size(); i++){
                        v.push_back({a[i], i});
                }
                // Sort 'a' (with indices) and 'b' to enable efficient counting
                sort(v.begin(), v.end());
                sort(b.begin(), b.end());
                vector<int> result(a.size(), 0); // To store the answer for each element in 'a'
                int n = a.size();
                int m = b.size();
                int j = 0; // Pointer for array 'b'
                // For each element in sorted 'a', count how many elements in 'b' are <= current 'a'
                for(int i = 0 ; i < n ; i++){
                        while(j < m && b[j] <= v[i].first){
                                j++;
                        }
                        // Store the count at the original index of the element in 'a'
                        result[v[i].second] = j;
                }
                return result;
        }
};