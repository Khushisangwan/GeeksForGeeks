#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> possibleWords(vector<int>& arr) {
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;
        string current;
        backtrack(arr, 0, current, result, mapping);
        return result;
    }

private:
    void backtrack(vector<int>& arr, int idx, string &current,
                   vector<string> &result, vector<string> &mapping) {
        if (idx == arr.size()) {
            if (!current.empty()) result.push_back(current); // only add non-empty words
            return;
        }

        string letters = mapping[arr[idx]];
        if (letters.empty()) {
            // skip digits 0 and 1
            backtrack(arr, idx + 1, current, result, mapping);
        } else {
            for (char ch : letters) {
                current.push_back(ch);
                backtrack(arr, idx + 1, current, result, mapping);
                current.pop_back();
            }
        }
    }
};