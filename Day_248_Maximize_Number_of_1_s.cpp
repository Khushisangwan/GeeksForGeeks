#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxOnes(vector<int>& arr, int k) {
                int n = arr.size();
                int i = 0, j = 0, count = 0, maxi = 0;  // i: left pointer, j: right pointer, count: zeros in window, maxi: max window size
                
                while(j < n) {
                        // If current element is 0, increment zero count
                        if(arr[j] == 0) count++;
                        
                        // Shrink window from left if zeros exceed k
                        while(count > k) {
                                if(arr[i] == 0) count--;  // Decrease zero count when removing a zero from window
                                i++;  // Move left pointer
                        }
                        
                        // Update maximum window size
                        maxi = max(maxi, j - i + 1);
                        j++;  // Expand window to the right
                }
                
                return maxi;  // Return maximum number of 1s possible
        }
};