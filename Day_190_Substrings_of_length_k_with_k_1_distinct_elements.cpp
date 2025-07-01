#include <bits/stdc++.h>
using namespace std;
// Problem: Substrings of length k with k-1 distinct elements
// Approach: Sliding Window Technique
// Steps:
class Solution {
    public:
        int substrCount(string &s, int k) {
                // Map to store frequency of characters in current window
                map<int,int> mp;
                int i=0, j=0, ans=0;
                // Traverse the string with sliding window
                while(j < s.size()){
                        mp[s[j]]++; // Add current character to map
                        // If window size is at least k
                        if(j-i+1 >= k){
                                // Shrink window if it exceeds size k
                                while(j-i+1 > k){
                                        mp[s[i]]--;
                                        if(mp[s[i]] == 0) mp.erase(s[i]);
                                        i++;
                                }
                                // If window has exactly k-1 distinct characters, increment answer
                                if(mp.size() == k-1) ans++;
                        }
                        j++;
                }
                return ans;
        }
};