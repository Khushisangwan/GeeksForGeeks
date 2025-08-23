#include<bits/stdc++.h>
using namespace std;

// Problem: Allocate Minimum Number of Pages
// Approach: Use binary search on the answer space to find the minimum number of pages

// Steps:
// 1. Define a function isPossible that checks if it is possible to allocate books such that no student reads more than mid pages.
// 2. Use binary search on the range [max(arr), sum(arr)] to find the minimum number of pages.
// 3. For each mid value in the binary search, use isPossible to check if the allocation is feasible.
// 4. If feasible, update the answer and search in the lower half.
// 5. If not feasible, search in the upper half.

// Time Complexity: O(n log(sum(arr) - max(arr))), where n is the number of books.
// Space Complexity: O(1) for the binary search and O(1) for the isPossible function.

class Solution {
  public:
  bool isPossible(vector<int> &arr, int k,int mid){
      int sum=0,student=1;
      for(int x:arr){
          sum+=x;
          if(sum>mid){
              student++;
              sum=x;
          }
          
      }
      return student<=k;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        int sum=0,mx=INT_MIN;
        for(int x:arr){
            sum+=x;
            mx=max(mx,x);
        }
        int low=mx,high=sum,mid,ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(isPossible(arr,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};