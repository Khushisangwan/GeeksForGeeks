
class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        map<int,int> mpp;
        set<int> st;
        
        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]]++;
            st.insert(arr[i]);
        }
        
        for(auto it : st){
            int freq = mpp[it];
            if(freq == 0) continue;
            for(int j = it; j < it + k; j++){
                if(mpp[j] < freq) return false;
                else {
                    mpp[j] -= freq;
                }
            }
        }
        return true;
    }
};