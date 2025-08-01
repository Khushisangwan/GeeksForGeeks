#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Count the number of subarrays where the difference between the number of vowels and consonants is zero
// Approach: Use a prefix sum technique with a hashmap to count the occurrences of each difference
// Steps:
// 1. Create a function to count the number of vowels in a string.
// 2. For each string, calculate the difference between the number of vowels and consonants.
// 3. Use a hashmap to keep track of the cumulative sum of differences.
// 4. For each difference, check how many times it has occurred before and add that to the answer.
// 5. Return the total count of balanced subarrays.
// Time Complexity: O(n), where n is the total number of characters in all strings, since we traverse each string once.
class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
          auto getCount = [&] (string s) {
            int ans = 0;
            string txt = "aeiou";
            for(char c :s){
                if(txt.find(string(1,c)) != string::npos) ans++;
            }
            return ans;
        };
        int n = arr.size();
        vector<int>vc(n);
        for(int i = 0;i<n;i++){
            vc[i] = getCount(arr[i]);
            vc[i] -= (arr[i].length() - vc[i]);
        }
        int ans = 0;
        map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += vc[i];
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};