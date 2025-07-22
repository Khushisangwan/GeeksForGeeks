#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Find the smallest positive missing number in the array `arr`.
// Approach: Use a hash set to track the numbers present in the array and find the smallest missing positive integer.
// Time Complexity: O(n), where n is the size of the array.
// Space Complexity: O(n), for the hash set.
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();
        unordered_set<int>st(arr.begin(), arr.end());
        
        int i=1;
        while(true){
            if(st.find(i)==st.end()) return i;
            i++;
        }
        
        return -1;
    }
};