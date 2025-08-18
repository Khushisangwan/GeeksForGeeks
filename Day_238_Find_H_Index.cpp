#include <bits/stdc++.h>
using namespace std;

// Problem: Calculate the h-index from a list of citation counts.
// Approach: Sort the citation counts and determine the maximum h-index.

// Steps:
// 1. Sort the citation counts in ascending order.
// 2. Iterate through the sorted list and calculate the h-index by checking how many papers have at least that many citations.
// 3. The h-index is the maximum value of min(citations[i], number of papers with at least that many citations).
// 4. Return the h-index.

// Time Complexity: O(n log n) due to sorting, where n is the number of citations.
// Space Complexity: O(1) if we sort in place, or O(n) if we use additional space for sorting.


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); // sort ascending
        int h = 0;
        
        for (int i = 0; i < n; i++) {
            int papersWithAtLeast = n - i;  // number of papers from i to n-1
            h = max(h, min(citations[i], papersWithAtLeast));
        }
        
        return h;
    }
};