#include <bits/stdc++.h>
using namespace std;
// Problem: Check if frequencies can be equal
class Solution {
    public:
        bool sameFreq(string& s) {
                // Vector to store frequency of each character (assuming lowercase a-z)
                vector<int> mp(26, 0);
                for(char ch : s) mp[ch - 'a']++; // Count frequency of each character

                unordered_set<int> ss; // To store unique frequencies
                int mx = 0, mn = 100000; // To track max and min frequencies
                unordered_map<int, int> freq; // To count how many times each frequency occurs

                for(int i = 0 ; i < 26 ; i++) {
                        if(mp[i] != 0) { // Only consider characters that appear in the string
                                ss.insert(mp[i]); // Add frequency to set
                                freq[mp[i]]++; // Count frequency occurrence
                                mx = max(mx, mp[i]); // Update max frequency
                                mn = min(mn, mp[i]); // Update min frequency
                        }
                }

                // If more than 2 unique frequencies, can't make all equal by removing one char
                if(ss.size() > 2) return false;

                // Three cases where it's possible:
                // 1. All frequencies are already equal
                // 2. Only one character has frequency 1 (can remove it)
                // 3. Only one character has the max frequency, and max is just one more than min (can remove one occurrence)
                if((mx == mn) || (mn == 1 && freq[mn] == 1) || (freq[mx] == 1 && mx - mn == 1)) return true;

                return false;
        }
};