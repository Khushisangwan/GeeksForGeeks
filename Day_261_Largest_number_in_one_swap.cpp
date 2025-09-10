class Solution {
  public:
    string largestSwap(string &s) {
        // code here
          int n=s.size();
        int ind=0;
        string t=s;
        sort(t.begin(), t.end(),greater<int>());
        int d =-1;
        for(int i=0;i<n;i++){
            if(t[i]!=s[i])
            {
                d=i;
                break;
            }
        }
        if (d==-1) return s;
        for(int i=n-1;i>=0;i--){
            if(t[d]==s[i]){
                swap(s[d],s[i]);
                break;
            }
        }
        
        return s;
    }
};