#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string firstNonRepeating(string &s) {
                // code here
                int n = s.length();
                vector<int> freq(26, 0);  // Frequency array for each character
                queue<int> q;  // Queue to maintain characters in order of appearance
                
                for(int i = 0; i < n; i++) {
                        freq[s[i] - 'a']++;  // Increment frequency of current character
                        
                        // If character appears for the first time, add to queue
                        if(freq[s[i] - 'a'] == 1) q.push(s[i]);
                        
                        // Remove characters from front of queue if they've been repeated
                        while(!q.empty() && freq[q.front() - 'a'] != 1) q.pop();
                        
                        // Update current position with first non-repeating character
                        if(!q.empty()) s[i] = q.front();
                        else s[i] = '#';  // No non-repeating character found
                }
                return s;
        }
};