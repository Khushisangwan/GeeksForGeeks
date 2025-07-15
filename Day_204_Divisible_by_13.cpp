#include <bits/stdc++.h>
using namespace std;

// Problem: Check if a number represented as a string is divisible by 13
// Approach: Direct Modulo Calculation

// Steps:
// 1. Initialize a variable to keep track of the remainder when the number is divided by 13.
// 2. Iterate through each character in the string, converting it to an integer.
// 3. Update the remainder using the formula: rem = (rem * 10 + digit) % 13.
// 4. After processing all characters, check if the remainder is zero.
// 5. If it is zero, the number is divisible by 13; otherwise, it is not.

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) since we are using a constant amount of space.

class Solution {
  public:
    bool divby13(string &s) {
        int rem =0;
        for(char x : s){
            rem = (rem*10+(x-'0'))%13;
        }
        
        return rem==0;
    }
};