#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string smallestWindow(string &s, string &p) {
                // Initialize frequency arrays for pattern and sliding window
                vector<int> countp(26,0);  // Frequency of characters in pattern p
                vector<int> counts(26,0);  // Frequency of characters in current window of s
                
                // If pattern is longer than string, no valid window exists
                if (p.size()>s.size())
                        return "";
                
                int distinctp=0, len=s.size(), match=0;
                
                // Count frequency of each character in pattern and find distinct characters
                for (int i=0; i<p.size(); i++){
                        if (countp[p[i]-'a']==0)
                                distinctp++;  // Count distinct characters in pattern
                        
                        countp[p[i]-'a']++;
                }
                
                // Two pointers for sliding window
                int left=0, right=0, start=0, end=s.size()-1;
                
                // Expand window by moving right pointer
                while (right<s.size()){
                        // Add current character to window
                        counts[s[right]-'a']++;
                        
                        // If frequency matches pattern frequency for this character
                        if (counts[s[right]-'a']==countp[s[right]-'a'])
                                match++;
                        
                        // If all distinct characters from pattern are matched
                        if (match==distinctp){
                                // Contract window from left while maintaining valid window
                                while (counts[s[left]-'a']>countp[s[left]-'a']){
                                        counts[s[left]-'a']--;
                                        left++;
                                }
                                
                                // Update minimum window if current is smaller
                                if (len>right-left+1){
                                        start=left;
                                        end=right;
                                        len=right-left+1;
                                }
                        }
                        
                        right++;
                }
                
                string ans="";
                // If no valid window found
                if (match<distinctp)
                        return "";
                else
                {
                        // Build result string from minimum window
                        for (int i=start; i<=end; i++){
                                ans+=s[i];
                        }
                        return ans;
                }
        }
};