class Solution {
  public:
    int countRevPairs(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }

  private:
    int mergeSort(vector<int> &a, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        int cnt = 0;
        cnt += mergeSort(a, l, m);
        cnt += mergeSort(a, m + 1, r);
        cnt += countCross(a, l, m, r);
        mergeHalves(a, l, m, r);
        return cnt;
    }

    int countCross(const vector<int> &a, int l, int m, int r) {
        int cnt = 0;
        int j = m + 1;
        for (int i = l; i <= m; ++i) {
            while (j <= r && (long long)a[i] > 2LL * (long long)a[j]) {
                ++j;
            }
            cnt += (j - (m + 1));
        }
        return cnt;
    }

    void mergeHalves(vector<int> &a, int l, int m, int r) {
        vector<int> tmp;
        tmp.reserve(r - l + 1);
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (a[i] <= a[j]) tmp.push_back(a[i++]);
            else              tmp.push_back(a[j++]);
        }
        while (i <= m) tmp.push_back(a[i++]);
        while (j <= r) tmp.push_back(a[j++]);
        for (int k = 0; k < (int)tmp.size(); ++k) a[l + k] = tmp[k];
    }
};