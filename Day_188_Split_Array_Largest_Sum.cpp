#include<bits/stdc++.h>
using namespace std;

// Problem: Split Array Largest Sum
// Approach: Binary Search

// Steps:
// 1. Define a function `f` that checks if it's possible to split the array into `k` or more parts such that the maximum sum of any part is less than or equal to a given `sum`.
// 2. Use binary search to find the minimum possible value of the maximum sum of any part when splitting the array into `k` parts.
// 3. The search space is between the maximum element in the array and the total sum of the array.
// 4. The answer is the minimum value of `sum` that allows the split.

// Time Complexity: O(n log(sum)), where n is the size of the array and sum is the total sum of the array.
// Space Complexity: O(1) for the binary search, O(n) for the input array.

class Solution {
    public:
        // Helper function to check if we can split the array into at most k parts
        // such that the largest sum among these parts is <= sum
        bool f(int sum , vector<int>& arr, int k){
             int s = 0 ; 
             for(int i : arr){
                     s += i ;
                     // If current sum exceeds the allowed sum, start a new subarray
                     if(s > sum){
                             k -- ; // Use one split
                             s = i ; // Start new subarray with current element
                     }
             }
             // Return true if we can split into at most k parts and last part is valid
             return (k > 0 && s <= sum) ;
        }
        
        // Main function to find the minimal largest sum after splitting array into k parts
        int splitArray(vector<int>& arr, int k) {
                // Lower bound: max element (can't split an element)
                int s = *max_element(arr.begin(), arr.end()) ; 
                // Upper bound: sum of all elements (no split)
                int e = accumulate(arr.begin() , arr.end() , 0) ;
                int ans = -1 ;
                // Binary search for the minimal largest sum
                while(s <= e){
                        int mid = s + (e-s) / 2 ;
                        if(f(mid , arr , k)){
                                ans = mid ;      // Possible, try for smaller sum
                                e = mid - 1 ;
                        }
                        else{
                                s = mid + 1 ;    // Not possible, try for larger sum
                        }
                }
                return ans ;
        }
};