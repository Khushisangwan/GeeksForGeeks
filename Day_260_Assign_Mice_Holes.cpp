#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int assignHole(vector<int>& mices, vector<int>& holes) {
                // Get the number of mice (which equals number of holes)
                int n = mices.size();
                
                // Step 1: Sort both arrays to enable optimal pairing
                // Sorting ensures we can pair each mouse with the nearest available hole
                sort(mices.begin(), mices.end());
                sort(holes.begin(), holes.end());
                
                // Step 2: Find the maximum time taken by any mouse to reach its assigned hole
                // The optimal strategy is to pair i-th mouse with i-th hole after sorting
                int maxTime = 0;
                for (int i = 0; i < n; i++) {
                        // Calculate time for current mouse to reach its assigned hole
                        // Update maxTime if current time is greater
                        maxTime = max(maxTime, abs(mices[i] - holes[i]));
                }
                
                // Return the maximum time (bottleneck time for all mice to reach holes)
                return maxTime;
        }
};