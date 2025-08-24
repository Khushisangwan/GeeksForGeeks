#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum days to make M bouquets
// Approach: Use binary search on the answer space to find the minimum number of days

// Steps:
// 1. Define a function ok that checks if it is possible to make m bouquets with k flowers each by day mid.
// 2. Use binary search on the range [min(arr), max(arr)] to find the minimum number of days.
// 3. For each mid value in the binary search, use ok to check if making the bouquets is feasible.
// 4. If feasible, update the answer and search in the lower half.
// 5. If not feasible, search in the upper half.
// 6. Return the minimum number of days found.

// Time Complexity: O(n log(max(arr) - min(arr))), where n is the number of flowers.
// Space Complexity: O(1) for the binary search and O(1) for the

class Solution {
  public:
    bool ok(vector<int> &arr,int k,int m,int mid){
        int n =arr.size();
        int cnt = 0;
        for(int i =0;i< n;i++){
            if(arr[i] <= mid){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt == k){
                cnt =0;
                m--;
            }
        }
        return m <= 0;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n =arr.size();
        if(n < m*k){
            return -1;
        }
        int l =*min_element(arr.begin(),arr.end());
        int r =*max_element(arr.begin(),arr.end());
        while(l <= r){
            int mid = l + (r-l)/2;
            if(ok(arr,k,m,mid)){
                r = mid -1;
            }else{
                l = mid +1;
            }
        }
        return l;
    }
};