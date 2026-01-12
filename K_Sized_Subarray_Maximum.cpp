#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> maxOfSubarrays(vector<int>& arr, int k) {
                // Store the maximum element and its index in the current window
                pair<int, int> mx = {INT_MIN, 0};
                vector<int> ans;
                
                // Iterate through the array
                for(int i = 0; i < arr.size(); i++) {
                        // If the previous maximum is outside the current window, recalculate
                        if(i > k - 1 && mx.second <= i - k) {
                                mx = {INT_MIN, 0};
                                // Find the maximum in the current window
                                for(int j = i - k + 1; j < i; j++) {
                                        mx = max(mx, {arr[j], j});
                                }
                        }
                        
                        // Update maximum with current element
                        mx = max(mx, {arr[i], i});
                        
                        // Add maximum to result once we have processed k elements
                        if(i >= k - 1)
                                ans.push_back(mx.first);
                }
                
                return ans;
        }
};