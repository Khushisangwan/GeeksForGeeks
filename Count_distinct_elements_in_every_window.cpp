#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> countDistinct(vector<int> &arr, int k) {
            vector<int> result;
        unordered_map<int, int> freqMap;

        // Initialize the frequency map with first k elements
        for (int i = 0; i < k; ++i) {
                freqMap[arr[i]]++;
        }

        // Add count of distinct elements in first window
        result.push_back(freqMap.size());

        // Slide the window through the rest of the array
        for (int i = k; i < arr.size(); ++i) {
                // Remove the leftmost element of previous window
                freqMap[arr[i - k]]--;
                if (freqMap[arr[i - k]] == 0) {
                        freqMap.erase(arr[i - k]);
                }

                // Add the new element to the window
                freqMap[arr[i]]++;

                // Store the count of distinct elements in current window
                result.push_back(freqMap.size());
        }

        return result;
        }
};