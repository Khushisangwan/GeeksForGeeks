class Solution {
  public:
    bool isCompleteBT(Node* root) {
        if(!root) return 1;
        queue<Node*> q;
        q.push(root);
        bool NULL_Encounter = false;
        
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            
            if(cur == NULL){                    // if(!cur)
                NULL_Encounter = true;
            }
            else{
                if(NULL_Encounter) return 0;
                q.push(cur -> left);
                q.push(cur -> right);
            }   
        }
        
        return 1;
    }
};