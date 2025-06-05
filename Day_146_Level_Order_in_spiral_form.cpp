#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
         vector<int> ans;
        
        queue<Node*> q;
        bool flag = false;
        q.push(root);
        stack<int> st;
        while(!q.empty()){
            int n = q.size();
      
            for(int i = 0 ; i < n ; i++){
                Node* node = q.front();
                
                q.pop();
                
               if(flag) ans.push_back(node -> data);
               
               else{
                   st.push(node -> data);
               }
                
                if(node -> left){
                    q.push(node -> left);
                }
                
                if(node -> right){
                    q.push(node -> right);
                }
            }
            
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            flag = !flag;
        }
        
        
        return ans;
    }
};
