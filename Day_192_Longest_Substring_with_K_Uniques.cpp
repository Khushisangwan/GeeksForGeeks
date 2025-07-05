#include <bits/stdc++.h>
using namespace std;

// Problem: Longest substring with exactly K distinct characters
// Approach: Sliding Window Technique

// Steps:
// 1. Use a sliding window to maintain the current substring.
// 2. Use a map to count the frequency of characters in the current window.
// 3. Expand the window by moving the right pointer.
// 4. If the number of distinct characters exceeds K, shrink the window from the left.
// 5. Keep track of the maximum length of the valid substring found.
// 6. Return the maximum length found.

// Time Complexity: O(n), where n is the length of the string
// Space Complexity: O(1) for the map, since we only store at most K distinct characters

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        int maxAns=-1;
        // traverse on the string
        int j=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        // calculate max value if we have excatly k distinct character
            if(mp.size()==k){
                int len=i-j+1;
                maxAns=max(maxAns,len);
            }
            // shrink window only if size of map is greater than k
            if(mp.size()>k){
                // remove value at jth pos
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
                
            }
        }
        return maxAns;
        
    }
    
};