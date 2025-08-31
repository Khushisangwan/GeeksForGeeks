#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxWater(vector<int> &arr) {
                // Two pointer approach to find maximum water container
                int l = 0;                    // Left pointer starting from beginning
                int h = arr.size() - 1;       // Right pointer starting from end
                
                int mx = 0;                   // Variable to store maximum water area
                
                // Continue until pointers meet
                while(l <= h){
                        // Calculate area: width * height (min of two heights)
                        mx = max(mx, (h - l) * min(arr[l], arr[h]));
                        
                        // Move pointer with smaller height inward
                        // This gives chance to find potentially larger area
                        if(arr[l] < arr[h]) 
                                l++;                  // Move left pointer right
                        else 
                                h--;                  // Move right pointer left
                }
                return mx;                    // Return maximum water area found
        }
};