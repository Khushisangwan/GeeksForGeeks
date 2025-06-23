class Solution {
  public:
    string minSum(vector<int> &arr) {
        string ans;
        int carry = 0;
        sort(arr.begin(), arr.end());
        for (int i = arr.size() - 1; i >= 0; i -= 2) {
            int sum = (arr[i] + (i - 1 >= 0 ? arr[i - 1] : 0) + carry);
            ans.push_back('0' + (sum % 10));
            carry = (sum / 10);
        }
        if (carry) ans.push_back('0' + carry);
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};