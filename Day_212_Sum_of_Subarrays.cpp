#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Calculate the sum of all subarrays of the array `arr`.
// Approach: Use the contribution technique to calculate the sum of all subarrays efficiently.
// Time Complexity: O(n), where n is the size of the array.
// Space Complexity: O(1), no extra space used.
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int ans = 0 ;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-i;
            ans+= (arr[i]*left*right);
        }
        return ans;
    }
};