#include <bits/stdc++.h>
using namespace std;

// Problem: Check if s1 is a subsequence of s2
// Approach: Use two pointers to traverse both strings

// Steps:
// 1. Initialize two pointers i and j to 0
// 2. Traverse both strings using the pointers
// 3. If characters match, move both pointers
// 4. If characters don't match, move the pointer of the second string
// 5. If we reach the end of s1, it is a subsequence
// 6. If we reach the end of s2 and haven't found all characters of s1, it is not a subsequence
// 7. If we reach the end of both strings and have found all characters of s1, it is a subsequence
// 8. If we reach the end of s1 and s2 at the same time, it is also a subsequence

// Time Complexity: O(n), where n is the length of the longer string
// Space Complexity: O(1)

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
          int i=0,j=0,n1=s1.length(),n2=s2.length();
       while(i<n1 && j<n2){
          
               if(s1[i]==s2[j]){
                   i++;j++;
               }
               else{
                   j++;
               }
           
       }
       if(i==n1)return true;
       else return false;
    }
};