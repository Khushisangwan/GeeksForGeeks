#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        // Create a sorted array with unique elements
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int m = sorted.size();
        
        // pos[i] stores all indices in arr where sorted[i] appears
        vector<vector<int>> pos(m);

        // Build position map for each unique element
        for (int i = 0; i < n; i++) {
            int id = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
            pos[id].push_back(i);
        }

        vector<int> res;
        res.reserve(queries.size());

        // Process each query
        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            // Find if x exists in the array
            auto it = lower_bound(sorted.begin(), sorted.end(), x);
            if (it == sorted.end() || *it != x) {
                res.push_back(0);
                continue;
            }

            // Get the index of x in sorted array
            int id = it - sorted.begin();
            auto &v = pos[id];

            // Count occurrences of x in range [l, r]
            int cnt = upper_bound(v.begin(), v.end(), r) -
                      lower_bound(v.begin(), v.end(), l);

            res.push_back(cnt);
        }
        return res;
    }
};