#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minJumps(vector<int>& arr) {
                // Find minimum number of jumps to reach the last index
                int n = arr.size();
                
                // Base cases
                if (n <= 1) return 0;          // Already at last index or empty array
                if (arr[0] == 0) return -1;    // Can't move anywhere from first position

                // Initialize variables for BFS-like approach
                int maxReach = arr[0];  // Farthest index reachable so far
                int steps = arr[0];     // Steps remaining in current jump range
                int jumps = 1;          // Number of jumps made (start with first jump)

                // Traverse the array starting from index 1
                for (int i = 1; i < n; i++) {
                        // If we've reached the last index, return number of jumps
                        if (i == n - 1) return jumps;

                        // Update the maximum reachable index from current position
                        maxReach = max(maxReach, i + arr[i]);
                        
                        // Decrement steps as we move forward
                        steps--;

                        // If no more steps left in current jump range
                        if (steps == 0) {
                                jumps++;                        // Make another jump
                                if (i >= maxReach) return -1;   // Check if we can't proceed further
                                steps = maxReach - i;           // Update steps for new jump range
                        }
                }
                
                return -1; // End is never reached
        }
};
