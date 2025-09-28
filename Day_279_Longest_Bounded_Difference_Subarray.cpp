#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> longestSubarray(vector<int>& arr, int x) {
                // Find the longest subarray where max - min <= x
                int n = arr.size();
                
                // Deques to maintain indices of max and min elements in current window
                deque<int> maxDq, minDq; // maxDq stores indices in decreasing order of values
                                                                // minDq stores indices in increasing order of values
                
                int left = 0, bestStart = 0, bestLen = 0; // Sliding window pointers and result tracking
        
                for (int right = 0; right < n; right++) {
                        // Maintain maxDq in decreasing order - remove smaller elements from back
                        while (!maxDq.empty() && arr[maxDq.back()] < arr[right]) 
                                maxDq.pop_back();
                        maxDq.push_back(right);
        
                        // Maintain minDq in increasing order - remove larger elements from back
                        while (!minDq.empty() && arr[minDq.back()] > arr[right]) 
                                minDq.pop_back();
                        minDq.push_back(right);
        
                        // Shrink window from left while max - min > x
                        while (arr[maxDq.front()] - arr[minDq.front()] > x) {
                                // Remove indices that are out of current window
                                if (maxDq.front() == left) maxDq.pop_front();
                                if (minDq.front() == left) minDq.pop_front();
                                left++; // Move left boundary
                        }
        
                        // Update best subarray if current window is longer
                        if (right - left + 1 > bestLen) {
                                bestLen = right - left + 1;
                                bestStart = left;
                        }
                }
        
                // Return the longest valid subarray
                return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
        }
};