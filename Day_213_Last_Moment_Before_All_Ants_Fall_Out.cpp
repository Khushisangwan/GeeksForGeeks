class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l =0, r=0;
        
        for(int i=0;i<left.size();i++)
            l = max(l,left[i]);
            
        
        for(int i=0;i<right.size();i++)
            r = max(r,n-right[i]);
        
        
        return max(l,r);
    }
};