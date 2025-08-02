
// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Find the length of the longest subarray where the number of elements greater than k is more than those less than or equal to k
// Approach: Use a prefix sum technique with a hashmap to track the cumulative sum of differences
// Steps:
// 1. Convert the array into a difference array where elements greater than k are +1 and others are -1.
// 2. Use a hashmap to store the first occurrence of each prefix sum.
// 3. Traverse the difference array, updating the prefix sum and checking if it has been seen before.
// 4. If the prefix sum is positive, update the maximum length to the current index + 1.
// 5. If the prefix sum is negative, check if (prefix - 1) exists in the hashmap to find the length of the subarray.
// 6. Return the maximum length found.
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
          int n=arr.size();
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            if(arr[i]>k){
                diff[i]=1;
            }
            else{
                diff[i]=-1;
            }
        }
        unordered_map<int,int>mp;
        int prefix=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            prefix+=diff[i];
            if(prefix>0){
                maxlen=i+1;
            }
            else{
                if(mp.find(prefix-1)!=mp.end()){
                    maxlen=max(maxlen,i-mp[prefix-1]);
                }
            }
            if(mp.find(prefix)==mp.end()){
                mp[prefix]=i;
            }
        }
        return maxlen;
    }
};