/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  
      struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
    };
    
    Node *flatten(Node *root) {
        
    
        priority_queue<Node*, vector<Node*>, Compare> pq;\
        Node* temp=root;
        Node* ans=temp;
        pq.push(temp);
        while(!pq.empty())
        {
            Node* curr = pq.top();
            pq.pop();
            if(curr->next)
            pq.push(curr->next);
            if(curr->bottom)
            pq.push(curr->bottom);
            if(curr==root)continue;
            temp->bottom=curr;
            temp=temp->bottom;
            
            
            
        }
        return ans;
    }
};