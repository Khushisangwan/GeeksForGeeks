class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        priority_queue<pair<int,int>>pq;
        for(auto it:x){
            pq.push({it,0});
        }
        for(auto it:y){
            pq.push({it,1});
        }
        int v=1,h=1;
        int sum=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int num=top.first;
            int axis=top.second;
            if(axis==0){
                sum+=(num*v);
                h++;
            }
            else{
                sum+=(num*h);
                v++;
            }
        }
        return sum;
        
    }
};