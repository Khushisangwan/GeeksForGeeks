#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxSubarrSum(vector<int>& arr, int a, int b) {
                // Find maximum sum of subarray with length between a and b (inclusive)
                int n = arr.size();
                int ans = INT_MIN;
                deque <int> q; // Monotonic deque to maintain minimum prefix sums
                
                // Build prefix sum array where pre[i] = sum of first i elements
                vector <int> pre(n+1, 0);
                for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + arr[i-1];
                
                // Iterate through all possible ending positions
                for(int i = a; i <= n; i++){
                        // Remove indices that are too far (window size > b)
                        while(!q.empty() && q.front() + b < i) q.pop_front();
                        
                        // Maintain monotonic property: remove larger prefix sums from back
                        while(!q.empty() && pre[q.back()] > pre[i-a]) q.pop_back();
                        
                        // Add current starting position to deque
                        q.push_back(i-a);
                        
                        // Update answer with current subarray sum
                        // pre[i] - pre[q.front()] gives sum of subarray ending at i-1
                        ans = max(ans, pre[i] - pre[q.front()]);
                }
                
                return ans;
        }
};