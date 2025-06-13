#include<bits/stdc++.h>
using namespace std;
// This code finds the k closest elements to a given value x in an array.

class Solution {
    public:
        // Custom comparator to sort pairs: first by absolute difference (ascending),
        // then by value (descending) if differences are equal
        static bool customCompare(pair<int, int> a, pair<int, int> b) {
                if (a.first == b.first) {
                        return a.second > b.second;
                }
                return a.first < b.first;
        }
        
        // Function to find k closest elements to x in the array
        vector<int> printKClosest(vector<int> arr, int k, int x) {
                vector<pair<int, int>> diff; // Stores pairs of (abs difference, value)
                
                // Calculate absolute difference for each element (skip if element == x)
                for (int a : arr) {
                        if (a == x) continue;
                        diff.push_back({abs(a - x), a});
                }
                
                // Sort the pairs using the custom comparator
                sort(diff.begin(), diff.end(), customCompare);
                
                vector<int> result;
                // Collect the first k elements (the k closest)
                for (int i = 0; i < k; i++) {
                        result.push_back(diff[i].second);
                }
                return result;
        }
};