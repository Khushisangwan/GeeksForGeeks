#include <bits/stdc++.h>
using namespace std;
// Class to find the smallest divisor of an array such that the sum of the quotients is less than or equal to k

class Solution {
    public:
        // Function to find the smallest divisor such that the sum of the quotients is <= k
        int smallestDivisor(vector<int>& arr, int k) {
                int n = arr.size();
                int low = 1;
                // Find the maximum element in the array
                int maxE = *max_element(arr.begin(), arr.end());
                // Set high as max element + k (safe upper bound)
                int high = maxE + k;
                int ans = high;
                // Binary search for the smallest divisor
                while(low <= high){
                        int mid = low + (high - low)/2;
                        int count = 0;
                        // Calculate the sum of quotients for current divisor mid
                        for(auto &e : arr){
                                count += ceil((double)e/mid);
                        }
                        // If sum is within k, try to find a smaller divisor
                        if(count <= k){
                                ans = min(mid, ans);
                                high = mid - 1;
                        }else{
                                // Otherwise, try a larger divisor
                                low = mid + 1;
                        }
                }
                return ans;
        }
};
