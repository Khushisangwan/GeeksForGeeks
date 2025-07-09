class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
         int n=arr.size();
       vector<int>left(n,-1);
       vector<int>right(n,n);
       //left will store the index of the first smaller elemtn to left
       //right will store the index of the first smaller elemtn to right
       
       //left
       //increasing stack
       stack<int>st1;
       for(int i=0;i<n;i++){
           while(!st1.empty()&&arr[st1.top()]>=arr[i]){
               st1.pop();
           }
           if(!st1.empty()){
               left[i]=st1.top();
           }
           st1.push(i);
       }
       //right
       //increasiing stack
       stack<int>st2;
       for(int i=n-1;i>=0;i--){
           while(!st2.empty()&&arr[st2.top()]>arr[i]){
               st2.pop();
           }
           if(!st2.empty()){
               right[i]=st2.top();
           }
           st2.push(i);
       }
       
       int ans=0;
       for(int i=0;i<n;i++){
           ans+=((i-left[i])*(right[i]-i)*arr[i]);
       }
        return ans;
    }
};