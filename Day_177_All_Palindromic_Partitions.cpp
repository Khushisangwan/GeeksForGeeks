#include <bits/stdc++.h>
using namespace std;
// Problem: All Palindromic Partitions
// Contest: LeetCode - Weekly Contest 352
// URL: https://leetcode.com/contest/weekly-contest-352/problems/all-palindromic-partitions/
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// You are given a string s.
// You can partition the string into substrings such that each substring is a palindrome.
// Return all possible palindromic partitions of the string.

class Solution {
    public:
    
        vector<vector<string>> res; // Stores all palindromic partitions
        
        // Function to check if a given string is a palindrome
        bool check(string &s){
                int start = 0 , end = s.length()-1;
                while(start <= end){
                        if(s[start] != s[end]) return false; // Not a palindrome
                        start++;
                        end--;
                }
                return true; // Is a palindrome
        }
        
        // Recursive function to find all palindromic partitions
        void solve(string &s , int i , vector<string>&temp){
                if(i >= s.length()){
                        res.push_back(temp); // Found a valid partition
                        return;
                }
                
                string tmp;
                for(int j=i;j<s.length();j++){
                        tmp.push_back(s[j]); // Build substring s[i..j]
                        if(check(tmp)){ // If substring is palindrome
                                temp.push_back(tmp); // Choose
                                solve(s,j+1,temp);   // Explore
                                temp.pop_back();     // Un-choose (backtrack)
                        }
                }
        }
    
        // Main function to return all palindromic partitions
        vector<vector<string>> palinParts(string &s) {
                vector<string> temp;
                solve(s,0,temp);
                return res;
        }
};