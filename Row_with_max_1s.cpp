class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int row = 0;
        int ans = -1;   // better default
        int idx = m - 1;

        while (row < n && idx >= 0) {
            if (arr[row][idx] == 1) {
                ans = row;
                idx--;
            } else {
                row++;
            }
        }
        return ans;
    }
};