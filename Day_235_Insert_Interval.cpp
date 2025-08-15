class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &itrl,
                                       vector<int> &nitr) {
        // code here
        itrl.push_back(nitr);
        int n=itrl.size();
        sort(itrl.begin(),itrl.end());
        for(int i=1;i<n;i++){
            auto x=itrl[i-1];
            auto y=itrl[i];
            if(x[1]>=y[0]){
                if(x[1]>=y[1]){
                    itrl[i]=itrl[i-1];
                    itrl[i-1][0]=-1;
                }
                else{
                    itrl[i][0]=itrl[i-1][0];
                    itrl[i-1][0]=-1;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:itrl){
            if(i[0]!=-1)ans.push_back(i);
        }
        return ans;
    }
};