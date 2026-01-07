
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
      vector<int> result;
    unordered_map<int, int> freqMap;

    for (int i = 0; i < k; ++i) {
        freqMap[arr[i]]++;
    }

    result.push_back(freqMap.size());

    for (int i = k; i < arr.size(); ++i) {
        freqMap[arr[i - k]]--;
        if (freqMap[arr[i - k]] == 0) {
            freqMap.erase(arr[i - k]);
        }

        freqMap[arr[i]]++;

        result.push_back(freqMap.size());
    }

    return result;
    }
};