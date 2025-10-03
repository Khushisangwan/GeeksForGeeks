#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main function to generate all possible words from phone digits
    vector<string> possibleWords(vector<int>& arr) {
        // Mapping of digits to their corresponding letters on phone keypad
        vector<string> mapping = {
            "",     // 0 - no letters
            "",     // 1 - no letters
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;  // Store all possible combinations
        string current;         // Current word being built
        backtrack(arr, 0, current, result, mapping);
        return result;
    }

private:
    // Recursive backtracking function to generate all combinations
    void backtrack(vector<int>& arr, int idx, string &current,
                   vector<string> &result, vector<string> &mapping) {
        // Base case: processed all digits
        if (idx == arr.size()) {
            if (!current.empty()) result.push_back(current); // only add non-empty words
            return;
        }

        // Get letters corresponding to current digit
        string letters = mapping[arr[idx]];
        if (letters.empty()) {
            // Skip digits 0 and 1 as they have no letters
            backtrack(arr, idx + 1, current, result, mapping);
        } else {
            // Try each letter for current digit
            for (char ch : letters) {
                current.push_back(ch);                        // Choose
                backtrack(arr, idx + 1, current, result, mapping); // Explore
                current.pop_back();                           // Backtrack
            }
        }
    }
};