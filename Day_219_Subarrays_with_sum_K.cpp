class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
         unordered_map<int,int> mp; 
        mp[0]=1;
        int size=arr.size();
        int res=0;
        int sum=0;
        for(int i=0;i<size;i++){ 
          sum+=arr[i];
          int rem = sum-k;
         if(mp.find(rem)!=mp.end()){
             res+=mp[rem];
         }
         mp[sum]++;
        }
        return res;
    }
};