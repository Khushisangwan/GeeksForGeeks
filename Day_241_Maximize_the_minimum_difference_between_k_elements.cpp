#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize the minimum difference between k elements
// Approach: Use binary search to find the maximum minimum distance that can be achieved

// Steps:
// 1. Sort the array of elements.
// 2. Use binary search to find the maximum minimum distance.
// 3. For each mid value in the binary search, check if it is possible to place k elements
//    such that the minimum distance between any two elements is at least mid.
// 4. If it is possible, update the answer and search for a larger distance.
// 5. If it is not possible, search for a smaller distance.

// Time Complexity: O(n log(max_diff)), where n is the number of elements and max_diff is the difference between the 
//                  maximum and minimum elements.
// Space Complexity: O(1) for the binary search, O(n) for sorting the array.

class Solution {
  public:
    bool canPlace(vector<int>& arr, int k, int dist) {
        int count = 1;          
        int last = arr[0];       
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= dist) { 
                count++;
                last = arr[i];
            }
            if (count >= k) return true;  
        }
        return false;  
    }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int s = 1,e = arr.back()-arr.front();
        int ans  = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(canPlace(arr,k,mid)){
                ans= mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};
