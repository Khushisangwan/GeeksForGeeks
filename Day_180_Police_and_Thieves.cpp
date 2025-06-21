#include <bits/stdc++.h>
using namespace std;
// Problem: Police and Thieves
// Contest: LeetCode - Weekly Contest 352
// URL: https://leetcode.com/contest/weekly-contest-352/problems/police-and-thieves/

class Solution {
    public:
        int catchThieves(vector<char> &arr, int k) {
                // Vectors to store indices of police ('P') and thieves ('T')
                vector<int>p, t;
                for(int i=0; i<arr.size(); i++){
                        if(arr[i] == 'P') 
                                p.push_back(i); // Store police index
                        else 
                                t.push_back(i); // Store thief index
                }
                
                int ans  = 0; // To count the number of thieves caught
                int st = 0;   // Pointer for police vector
                // Iterate through all thieves
                for(int i=0; i<t.size(); i++){
                        while(st < p.size()){
                                int low = t[i] - k;   // Minimum index police can catch this thief
                                int high = t[i] + k;  // Maximum index police can catch this thief
                                if(p[st] <= high && p[st] >= low){
                                        // Police at p[st] can catch thief at t[i]
                                        ans++;
                                        st++; // Move to next police
                                        break;
                                }
                                else if(p[st] < low){
                                        // Police is too far left, move to next police
                                        st++;
                                }
                                else{
                                        // Police is too far right, break to next thief
                                        break;
                                }
                        }
                }
                return ans;
        }
};