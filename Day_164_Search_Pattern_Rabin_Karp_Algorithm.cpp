#include <bits/stdc++.h>
using namespace std;
// Search for all occurrences of a pattern in a given text using Rabin-Karp algorithm.
// This code uses a sliding window approach with frequency counting to efficiently find all occurrences of the pattern in the text.

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int n = txt.length();
        int m = pat.length();
        
        vector <int> ans;
        vector <int> freqPt(26, 0);
        vector <int> freqTxt(26, 0);
        
        for(int i = 0; i < m; i++){
            freqPt[pat[i] - 'a']++;
            freqTxt[txt[i] - 'a']++;
        }
        
        for(int i = 0; i <= n-m; i++){
            if(freqPt == freqTxt){
                bool match = true;
                for(int j = 0; j < m; j++){
                    if(pat[j] != txt[i + j]){
                        match = false;
                        break;
                    }
                }
                
                if(match) ans.push_back(i+1);
            }
            
             if (i + m < n) {
                freqTxt[txt[i] - 'a']--;
                freqTxt[txt[i + m] - 'a']++;
            }
        }
        
        return ans;
    }

};