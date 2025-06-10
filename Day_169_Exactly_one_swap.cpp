class Solution {
  public:
    int countStrings(string &s) {
        int countofunique = 0;
        bool flag = false;
        vector<int> v(26, 0);
        for(auto c: s){
            if(!flag && v[c-'a']) flag =true;
            if(v[c-'a'] == 0) countofunique ++;
            v[c-'a']++;
        }
        long long ans = 0;
        int n = s.length();
        for(int i=0; i<26; i++)
        {
            int count = v[i];
            int number = 0;
            if(v[i]>0)
            {
                // other numbers * number of chars they can be replaced with
                number = (n-v[i])*v[i]; 
                ans += number;
            }
        }
        // because ans counted will have duplicacy since we are couting twice
        ans /= 2;
        if(flag) 
        ans++;
        
        return (int)ans;
    }
};