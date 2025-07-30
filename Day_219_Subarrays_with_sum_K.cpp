#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Count the number of subarrays with a sum equal to k
// Approach: Use a hashmap to store the frequency of prefix sums
// Time Complexity: O(n), where n is the length of the array.
// Space Complexity: O(n), for storing the prefix sums in the hashmap.

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
         unordered_map<int,int> mp; 
        mp[0]=1;
        int size=arr.size();
        int res=0;
        int sum=0;
        for(int i=0;i<size;i++){ 
          sum+=arr[i];
          int rem = sum-k;
         if(mp.find(rem)!=mp.end()){
             res+=mp[rem];
         }
         mp[sum]++;
        }
        return res;
    }
};