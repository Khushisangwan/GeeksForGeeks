class Solution {
  public:
    bool ok(vector<int> &arr,int k,int m,int mid){
        int n =arr.size();
        int cnt = 0;
        for(int i =0;i< n;i++){
            if(arr[i] <= mid){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt == k){
                cnt =0;
                m--;
            }
        }
        return m <= 0;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n =arr.size();
        if(n < m*k){
            return -1;
        }
        int l =*min_element(arr.begin(),arr.end());
        int r =*max_element(arr.begin(),arr.end());
        while(l <= r){
            int mid = l + (r-l)/2;
            if(ok(arr,k,m,mid)){
                r = mid -1;
            }else{
                l = mid +1;
            }
        }
        return l;
    }
};