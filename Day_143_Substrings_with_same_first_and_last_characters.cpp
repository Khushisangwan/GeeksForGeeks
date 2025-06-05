#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countSubstring(string &s) {
        // code here
         int n = s.length();
        
        vector<int> freq(26);
        
        int cnt = 0;
        
        for(int i = 0; i<n; i++) {
            freq[s[i]-'a']++;
        }
        
        for(int c : freq) {
            if(c > 0)
                cnt += (((c)*(c-1))/(2));
        }
        
        return (cnt + n);
    }
};