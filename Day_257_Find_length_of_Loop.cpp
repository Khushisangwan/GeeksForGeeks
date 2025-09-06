

/*
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Function to find the length of a loop in the linked list.
    public int countNodesinLoop(Node head) {
        // code here.
        
        // Create a HashMap to store nodes and their positions
        Map<Node,Integer> hm=new HashMap<>();
        int len=1; // Position counter starting from 1
        Node curr=head; // Current node pointer
        
        // Traverse the linked list
        while(curr!=null){
            // If current node is already visited, loop detected
            if(hm.containsKey(curr)) 
                return len-hm.get(curr); // Return loop length
            
            // Store current node with its position
            hm.put(curr,len);
            len++; // Increment position counter
            curr=curr.next; // Move to next node
        }
        
        // No loop found, return 0
        return 0;
    }
}