#include <bits/stdc++.h>
using namespace std;
// Search for all occurrences of a pattern in a given text using Rabin-Karp algorithm.
// This code uses a sliding window approach with frequency counting to efficiently find all occurrences of the pattern in the text.

class Solution {
    public:
        // Function to search for all occurrences of pattern 'pat' in text 'txt'
        vector<int> search(string &pat, string &txt) {
                int n = txt.length(); // Length of text
                int m = pat.length(); // Length of pattern
                
                vector <int> ans; // Stores starting indices (1-based) of matches
                vector <int> freqPt(26, 0); // Frequency of each character in pattern
                vector <int> freqTxt(26, 0); // Frequency of each character in current window of text
                
                // Initialize frequency arrays for pattern and first window of text
                for(int i = 0; i < m; i++){
                        freqPt[pat[i] - 'a']++;
                        freqTxt[txt[i] - 'a']++;
                }
                
                // Slide the window over the text
                for(int i = 0; i <= n-m; i++){
                        // If frequency arrays match, check for actual substring match
                        if(freqPt == freqTxt){
                                bool match = true;
                                for(int j = 0; j < m; j++){
                                        if(pat[j] != txt[i + j]){
                                                match = false;
                                                break;
                                        }
                                }
                                
                                if(match) ans.push_back(i+1); // Store 1-based index if match found
                        }
                        
                        // Move the window: remove leftmost char and add next char
                        if (i + m < n) {
                                freqTxt[txt[i] - 'a']--;
                                freqTxt[txt[i + m] - 'a']++;
                        }
                }
                
                return ans; // Return all starting indices of matches
        }

};