class Solution {
  public:
     int totalElements(vector<int> &arr) {
        // code here
        int ans=0;
        int i=0,j=0;
        map<int,int> mp;
        while(j<arr.size()){
            mp[arr[j]]++;
            int c=mp.size();
            while(c>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                    c--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};