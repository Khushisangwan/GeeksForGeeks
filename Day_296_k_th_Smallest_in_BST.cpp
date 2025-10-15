/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int &k) {
       if(root==NULL)
        return -1;
        int left=kthSmallest(root->left,k);
        if(left!=-1)
        {
        return left;
        }
        k--;
        if(k==0)
        {
        return root->data;
        }
       return kthSmallest(root->right,k); 
    }
};