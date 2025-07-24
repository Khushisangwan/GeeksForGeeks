#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Calculate the last moment before all ants fall out of a line of length `n`.
// Approach: Track the farthest left and right movements of ants to determine the last moment.
// Time Complexity: O(m), where m is the number of ants.
// Space Complexity: O(1), no extra space used.
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l =0, r=0;
        
        for(int i=0;i<left.size();i++)
            l = max(l,left[i]);
            
        
        for(int i=0;i<right.size();i++)
            r = max(r,n-right[i]);
        
        
        return max(l,r);
    }
};