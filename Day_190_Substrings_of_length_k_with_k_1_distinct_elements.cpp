#include <bits/stdc++.h>
using namespace std;
// Problem: Substrings of length k with k-1 distinct elements
// Approach: Sliding Window Technique
// Steps:
class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
         map<int,int> mp;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(j-i+1>=k){
                while(j-i+1>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                if(mp.size()==k-1)ans++;
            }
            j++;
        }
        return ans;
    }
};