#include <bits/stdc++.h>
using namespace std;
// Problem: Count the number of unique vowel strings that can be formed using the characters in a given string.
// Approach: We can use a map to count the frequency of each vowel in the string. The result is calculated as the product of the factorial of the number of unique vowels and the product of their frequencies.

class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        map<char, int> mp;
        
        for(char c: s)
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') mp[c]++;
            
        int sz = mp.size(), ans = sz;
        
        
        for(int i = 2; i<sz; i++)  ans *= i;
        for(auto it: mp)    ans *= it.second;
        
        return ans;
    }
};