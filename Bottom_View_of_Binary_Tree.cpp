/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
         map<int, int>map;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0;i<size;i++){
                auto front = q.front(); q.pop();
                
                map[front.second] = front.first->data;
                
                if(front.first->left)  q.push({front.first->left, front.second-1});
                if(front.first->right)  q.push({front.first->right, front.second+1});
            }
        }
        
        vector<int> ans;
        
        for(auto i : map){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};