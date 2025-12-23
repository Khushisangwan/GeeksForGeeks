#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
                // Optimize I/O for faster execution
                ios_base::sync_with_stdio(false);
                
                vector<int> res;
                
                // Sort the array to enable binary search
                sort(arr.begin(), arr.end());
                
                // Process each query
                for(auto query : queries){
                        int a = query[0];  // Lower bound of range
                        int b = query[1];  // Upper bound of range
                        
                        // Find first element >= a
                        auto low = lower_bound(arr.begin(), arr.end(), a);
                        
                        // Find first element > b
                        auto high = upper_bound(arr.begin(), arr.end(), b);
                        
                        // Count elements in range [a, b]
                        int cnt = high - low;
                        res.push_back(cnt);
                }
                
                return res;
        }
};