#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int searchInsertK(vector<int> &arr, int k) {
                // Initialize pointers for binary search
                int start = 0, end = arr.size()-1;
                
                // Binary search to find insertion position
                while (start <= end) {
                        int mid = start + (end - start) / 2;
                        
                        // If middle element is less than k, search right half
                        if (arr[mid] < k) { 
                                start = mid + 1;
                        } else { 
                                // Otherwise, search left half
                                end = mid - 1; 
                        }
                }
                
                // Return the insertion position
                return start;
        }
};