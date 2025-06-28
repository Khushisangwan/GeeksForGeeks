#include<bits/stdc++.h>
using namespace std;
// Problem: Count elements less than or equal to each element in the first array from the second array
// Link: https://leetcode.com/problems/count-elements-in-two-arrays/description/
// Difficulty: Medium
// Time Complexity: O(nlogn + mlogm) where n is the size of the first array and m is the size of the second array

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // cosort(de here
        vector<pair<int,int>>v;
        for(int i = 0 ; i<a.size(); i++){
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        sort(b.begin(),b.end());
        vector<int>result(a.size(),0);
        int n = a.size();
        int m = b.size();
        int j = 0;
        for(int i = 0 ; i<n ; i++){
            while(j<m && b[j]<=v[i].first){
                j++;
            }
            result[v[i].second]=j;
        }
        return result;
    }
};