class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        vector<pair<int,int>>v;
        
        for(int i=0;i<color.size();i++){
            if(!v.empty() && v.back().first==color[i] && v.back().second==radius[i]){
                v.pop_back();
            }else{
                v.push_back({color[i],radius[i]});
            }
        }
        return v.size();
    }
};