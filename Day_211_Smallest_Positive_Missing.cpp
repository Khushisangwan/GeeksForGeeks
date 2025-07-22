class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();
        unordered_set<int>st(arr.begin(), arr.end());
        
        int i=1;
        while(true){
            if(st.find(i)==st.end()) return i;
            i++;
        }
        
        return -1;
    }
};