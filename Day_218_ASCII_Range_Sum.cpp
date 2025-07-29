class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
         unordered_map<char, vector<int>> mp;
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) mp[s[i]].push_back(i);
        for (char ch = 'a'; ch <= 'z'; ch++){
            if (mp[ch].size() >= 2){
                int f = mp[ch].front(), l = mp[ch].back();
                int sum = 0;
                for (int i = f+1; i < l; i++){
                    sum += s[i];
                }
                // cout << ch << endl;
                if (sum != 0) ans.push_back(sum);
            }
        }
        return ans;
    }
};