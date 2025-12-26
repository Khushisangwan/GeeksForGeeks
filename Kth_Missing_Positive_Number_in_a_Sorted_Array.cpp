class Solution {
  public:
     int kthMissing(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int left=0,right=n-1,mid;
        if(arr[0]>k){
            return k;
        }
        while(left<=right){
            mid=(left+right)/2;
            if((arr[mid]-(mid+1))<k){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        if(right==-1){
            return k;
        }
        return arr[right]+(k-(arr[right]-(right+1)));
    }
};