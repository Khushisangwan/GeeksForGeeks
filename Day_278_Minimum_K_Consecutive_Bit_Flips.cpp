#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int kBitFlips(vector<int>& arr, int k) {
                int n = arr.size();
                queue<int> q; // Queue to track end positions of active flip operations
                int operation = 0; // Count of flip operations performed
                
                for(int i = 0; i < n; i++){
                        // Remove expired flip operations (those that ended before current position)
                        if(!q.empty() && i == q.front()) q.pop();
                        
                        int bit = arr[i]; // Current bit value
                        
                        // If odd number of active flips, the current bit is flipped
                        if(!q.empty() && q.size() % 2 == 1) bit ^= 1;
                        
                        // If current effective bit is 0, we need to flip
                        if(bit == 0){
                                // Check if we can perform k-bit flip starting at position i
                                if(i + k > n) return -1; // Not enough elements remaining
                                
                                operation++; // Increment operation count
                                q.push(i + k); // Mark end position of this flip operation
                        }
                }
                return operation;
        }
};