#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Check if a given sentence is a palindrome
// Approach: Ignore non-alphanumeric characters and case, then check if the string reads the same forwards and backwards
// Steps:
// 1. Iterate through the string and build a new string containing only alphanumeric characters in lowercase.
// 2. Use two pointers to compare characters from the start and end of the new string.
// 3. If all characters match, the sentence is a palindrome; otherwise, it is not.
// Time Complexity: O(n), where n is the length of the input string

class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
         string check;
        for (char ch : s)
        {
            if (isalnum(ch)) check += tolower(ch);
        }
        
        int l = 0, r = check.size() - 1;
        while (l < r)
        {
            if (check[l++] != check[r--]) return false;
        }

        return true;
    }
};