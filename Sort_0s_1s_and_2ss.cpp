class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int cnt0=0,cnt1=0,cnt2=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                cnt0++;
            }else if(arr[i]==1){
                cnt1++;
            }else{
                cnt2++;
            }
        }
        int i=0;
        while(cnt0--){
            arr[i++]=0;
        }
        while(cnt1--){
            arr[i++]=1;
        }
        while(cnt2--){
            arr[i++]=2;
        }
    }
};

