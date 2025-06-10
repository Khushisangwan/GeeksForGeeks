#include<bits/stdc++.h>
using namespace std;
// This code counts the number of unique strings that can be formed by swapping characters in a given string.

class Solution {
    public:
        // Function to count the number of unique strings that can be formed by exactly one swap
        int countStrings(string &s) {
                int countofunique = 0; // Count of unique characters in the string
                bool flag = false;     // Flag to check if any character repeats
                vector<int> v(26, 0);  // Frequency array for each lowercase letter

                // Count frequency of each character and check for duplicates
                for(auto c: s){
                        if(!flag && v[c-'a']) flag = true; // Set flag if duplicate found
                        if(v[c-'a'] == 0) countofunique++; // Increment unique count
                        v[c-'a']++;
                }

                long long ans = 0;
                int n = s.length();
                // For each character, calculate possible swaps with other characters
                for(int i = 0; i < 26; i++)
                {
                        int count = v[i];
                        int number = 0;
                        if(v[i] > 0)
                        {
                                // Each occurrence of character i can be swapped with any other character
                                number = (n - v[i]) * v[i]; 
                                ans += number;
                        }
                }
                // Each swap is counted twice (i, j) and (j, i), so divide by 2
                ans /= 2;
                // If there is any duplicate character, swapping two same characters doesn't change the string,
                // so we can add one more unique string (the original string itself)
                if(flag) 
                        ans++;
                
                return (int)ans;
        }
};