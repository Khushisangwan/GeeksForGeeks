/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  
    Node* mergeTwo(Node* h1, Node* h2){
        Node* dummyHead = new Node(-1);
        Node* curr = dummyHead;
        
        while(h1 != NULL && h2 != NULL){
            if(h1->data <= h2->data){
                curr->next = h1;
                h1 = h1->next;
            }
            else{
                curr->next = h2;
                h2 = h2->next;
            }
            curr = curr->next;
        }
        
        if(h1 != NULL){
            curr->next = h1;
        }
        else{
            curr->next = h2;
        }
        
        return dummyHead->next;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        Node* res = NULL;
        for(Node* node : arr){
            res = mergeTwo(res, node);
        }
        return res;
    }
};

