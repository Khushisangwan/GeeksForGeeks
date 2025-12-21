#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int m = sorted.size();
        vector<vector<int>> pos(m);

        for (int i = 0; i < n; i++) {
            int id = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
            pos[id].push_back(i);
        }

        vector<int> res;
        res.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            auto it = lower_bound(sorted.begin(), sorted.end(), x);
            if (it == sorted.end() || *it != x) {
                res.push_back(0);
                continue;
            }

            int id = it - sorted.begin();
            auto &v = pos[id];

            int cnt = upper_bound(v.begin(), v.end(), r) -
                      lower_bound(v.begin(), v.end(), l);

            res.push_back(cnt);
        }
        return res;
    }
};