#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int sumOfModes(vector<int>& arr, int k) {
                // code here
                int n = arr.size();
                unordered_map<int, int> freq; // Frequency map for elements in current window
                set<pair<int, int>> ss; // Set to maintain elements sorted by frequency (descending) then by value
                int modeSum = 0;

                int i = 0, j = 0;
                
                // Build initial window of size k
                while (j - i != k) {
                        int val = arr[j];
                        // Create pair with negative frequency for descending order in set
                        pair<int, int> p = {n - freq[val], val};
                        
                        // Remove old frequency entry if exists
                        if (ss.find(p) != ss.end()) {
                                ss.erase(p);
                        }
                        
                        freq[val]++; // Increment frequency
                        p = {n - freq[val], val}; // Update pair with new frequency
                        ss.insert(p); // Insert updated pair
                        j++;
                }

                // Add mode (element with highest frequency) of first window
                modeSum += (*ss.begin()).second;

                // Slide the window
                while (j < n) {
                        // Remove leftmost element from window
                        int val = arr[i];
                        pair<int, int> p = {n - freq[val], val};
                        if (ss.find(p) != ss.end()) {
                                ss.erase(p);
                        }
                        freq[val]--; // Decrement frequency
                        p = {n - freq[val], val};
                        ss.insert(p);

                        // Add rightmost element to window
                        val = arr[j];
                        p = {n - freq[val], val};
                        if (ss.find(p) != ss.end()) {
                                ss.erase(p);
                        }
                        freq[val]++; // Increment frequency
                        p = {n - freq[val], val};
                        ss.insert(p);

                        // Add mode of current window to sum
                        modeSum += (*ss.begin()).second;
                        i++;
                        j++;
                }
                return modeSum;
        }
};