#include <bits/stdc++.h>
using namespace std;

// Problem: Max Min Height
// Approach: Binary Search

// Steps:
// 1. Define a function `check` that determines if it's possible to achieve a minimum height `t` with the given constraints.
// 2. Use a binary search to find the maximum possible minimum height.
// 3. The search space is between the minimum height in the array and the maximum height that can be achieved by adding `k` water units.
// 4. For each mid value in the binary search, call the `check` function
//    to see if it's feasible to achieve that height.
// 5. If it is feasible, move the lower bound up; otherwise, move the upper bound down.
// 6. The result will be the highest feasible minimum height found.

// Time Complexity: O(n log(max(arr) + k))
// Space Complexity: O(n)

class Solution {
  public:
    bool check(int t, int n, int k, int w, vector<int>&arr){
        int currWater=0;
        int dayUsed=0;
        vector<int>water(n+1, 0);
        
        for(int i=0; i<n; i++){
            currWater+=water[i];
            int currHeight=arr[i]+currWater;
            if(currHeight<t){
                int need=t-currHeight;
                dayUsed+=need;
                if(dayUsed>k) return false;
                currWater+=need;
                water[i]+=need;
                if(i+w<=n){
                    water[i+w]-=need;
                }
            }
        }
        
        return true;
    }
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int n=arr.size();
        int lo = *min_element(arr.begin(), arr.end());
        int hi=lo+k;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid, n, k, w, arr)){
                lo=mid+1;
            }else hi=mid-1;
        }
        return hi;
    }
};