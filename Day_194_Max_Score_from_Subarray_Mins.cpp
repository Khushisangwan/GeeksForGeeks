#include<bits/stdc++.h>
using namespace std;
// Problem: Max Score from Subarray Mins
// Link: https://leetcode.com/problems/max-score-from-subarray-mins/
// Difficulty: Medium
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int count=0;
        for(int i=0;i<arr.size()-1;i++)
            count=max(count,arr[i]+arr[i+1]);
        
        return count;
    }
};