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
    bool f(int sum , vector<int>& arr, int k){
       int s = 0 ; 
       for(int i : arr){
           s += i ;
           if(s > sum){
               k -- ; s = i ;
           }
       }
       return (k > 0 && s <= sum) ;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int s = *max_element(arr.begin(), arr.end()) ; 
        int e = accumulate(arr.begin() , arr.end() , 0) ;
        int ans = -1 ;
        while(s <= e){
            int mid = s + (e-s) / 2 ;
            if(f(mid , arr , k)){
                ans = mid ;
                e = mid - 1 ;
            }
            else{
                s = mid + 1 ;
            }
        }
        return ans ;
    }
};