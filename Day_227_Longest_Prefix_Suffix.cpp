#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Find the length of the longest prefix which is also a suffix in a given string
// Approach: Iterate through the string to find all starting positions of the first character and check for matches
// Steps:
// 1. Store the first character of the string.
// 2. Iterate through the string to find all indices where the first character appears.
// 3. For each index, check if the substring starting from that index matches the prefix of the string.
// 4. If a match is found, return the length of the suffix.
// Time Complexity: O(n^2), where n is the length of the string, due to nested loops
class Solution {
  public:
    int getLPSLength(string &s) {
        char ch = s[0];
        int n = s.length();
        vector<int>idx;
        for (int i=1; i<n; i++){
            if (s[i] == ch) idx.push_back(i);
        }
        
        for (int i=0; i<idx.size(); i++){
            int j = 0, t = idx[i];
            int ok = true;
            while (t < n){
                if (s[j] == s[t]){
                    j+=1;
                    t+=1;
                }
                else {
                    ok = false;
                    break;
                }
            }
            if (ok) return n - idx[i];
        }
        return 0;
    }
};