bool canPlace(vector<int>& arr, int k, int dist) {
        int count = 1;          
        int last = arr[0];       
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= dist) { 
                count++;
                last = arr[i];
            }
            if (count >= k) return true;  
        }
        return false;  
    }
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int s = 1,e = arr.back()-arr.front();
        int ans  = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(canPlace(arr,k,mid)){
                ans= mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }