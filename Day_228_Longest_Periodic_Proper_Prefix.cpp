#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Find the length of the longest periodic proper prefix in a given string
// Approach: Use a two-pointer technique to find the longest prefix that matches a suffix
// Steps:
// 1. Initialize a pointer to the end of the string.
// 2. Use a while loop to check if the characters at the current suffix position match the prefix.
// 3. If they match, move both pointers forward.
// 4. If the suffix pointer reaches the end of the string, return the length of the prefix.
// 5. If no match is found, decrement the suffix pointer and repeat.
// Time Complexity: O(n), where n is the length of the string, as each character is checked at most once.
// Space Complexity: O(1), as no additional space is used.
class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
          int n = s.size();
        int len = s.size()-1;
        
        while(len){
            int sPtr = len;
            int i = 0;
            
            while(sPtr<n){
                if(s[sPtr] == s[i]){
                    i++;
                    sPtr++;
                }
                else{
                    break;
                }
            }
            
            if(sPtr==n)
              return len;
            
            len--;
        }
        
        
        return -1;
    }
};