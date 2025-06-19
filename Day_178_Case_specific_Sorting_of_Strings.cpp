#include <bits/stdc++.h>
using namespace std;
// Problem: Case-specific Sorting of Strings
// Contest: LeetCode - Weekly Contest 352
// URL: https://leetcode.com/contest/weekly-contest-352/problems/case-specific-sorting-of-strings/
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// You are given a string s.
// You can sort the string in such a way that all uppercase letters appear before all lowercase letters
// and the relative order of uppercase letters and lowercase letters remains unchanged.

class Solution {
  public:
    string caseSort(string& s) {
        // code here
         string p = s;
        sort(p.begin(), p.end());
        int i = 0;
        for(auto& ch : s){
            if(isupper(ch)){
                ch = p[i++];
            }
        }
        for(auto& ch : s){
            if(islower(ch)){
                ch = p[i++];
            }
        }
        return s;
    }
};