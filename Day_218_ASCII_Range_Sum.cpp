#include<bits/stdc++.h>
using namespace std;
// Problem Statement: Calculate the ASCII range sum for characters in a string
// Approach: Use a map to store indices of characters, then calculate the sum of ASCII values
// between the first and last occurrences of each character that appears at least twice
// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), no extra space used apart from the map for character indices.
// Note: The solution assumes that the input string contains lowercase letters only.
class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
         unordered_map<char, vector<int>> mp;
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) mp[s[i]].push_back(i);
        for (char ch = 'a'; ch <= 'z'; ch++){
            if (mp[ch].size() >= 2){
                int f = mp[ch].front(), l = mp[ch].back();
                int sum = 0;
                for (int i = f+1; i < l; i++){
                    sum += s[i];
                }
                // cout << ch << endl;
                if (sum != 0) ans.push_back(sum);
            }
        }
        return ans;
    }
};