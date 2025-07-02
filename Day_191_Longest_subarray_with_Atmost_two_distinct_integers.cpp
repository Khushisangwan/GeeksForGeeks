#include <bits/stdc++.h>
using namespace std;

// Problem: Longest subarray with at most two distinct integers
// Approach: Sliding Window Technique

// Steps:
// 1. Use a sliding window to maintain the current subarray.
// 2. Use a map to count the frequency of elements in the current window.
// 3. Expand the window by moving the right pointer.
// 4. If the number of distinct elements exceeds two, shrink the window from the left
// 5. Keep track of the maximum length of the valid subarray found.
// 6. Return the maximum length found.

// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(1) for the map, since we only store at most two distinct integers

class Solution {
  public:
     int totalElements(vector<int> &arr) {
        // code here
        int ans=0;
        int i=0,j=0;
        map<int,int> mp;
        while(j<arr.size()){
            mp[arr[j]]++;
            int c=mp.size();
            while(c>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                    c--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};