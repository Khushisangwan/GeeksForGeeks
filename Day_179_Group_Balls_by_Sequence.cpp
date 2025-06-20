
#include<bits/stdc++.h>
using namespace std;
// Problem: Group Balls by Sequence
// Contest: LeetCode - Weekly Contest 352
// URL: https://leetcode.com/contest/weekly-contest-352/problems/group-balls-by-sequence/
class Solution {
    public:
        // Function to check if the array can be grouped into sequences of length k
        bool validgroup(vector<int> &arr, int k) {
                map<int,int> mpp; // Map to store frequency of each number
                set<int> st;      // Set to store unique numbers in sorted order
                
                // Count frequency of each number and insert into set
                for(int i = 0; i < arr.size(); i++){
                        mpp[arr[i]]++;
                        st.insert(arr[i]);
                }
                
                // Try to form groups starting from the smallest number
                for(auto it : st){
                        int freq = mpp[it]; // Frequency of current number
                        if(freq == 0) continue; // Already used in previous groups
                        // Check if we can form a group of size k starting from 'it'
                        for(int j = it; j < it + k; j++){
                                if(mpp[j] < freq) // Not enough numbers to form a group
                                        return false;
                                else {
                                        mpp[j] -= freq; // Use up 'freq' numbers for this group
                                }
                        }
                }
                return true; // All groups formed successfully
        }
};