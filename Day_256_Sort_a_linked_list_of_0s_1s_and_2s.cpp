
/* class Node
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        next = null;
    }
}*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static Node segregate(Node head) {
        // code here
        
        // Count occurrences of 0s, 1s, and 2s
        int zero = 0, one = 0, two = 0;
        Node curr = head;
        
        // First pass: count the frequency of each value
        while(curr != null) {
            if(curr.data == 0) {
                zero++;
            }
            else if(curr.data == 1) {
                one++;
            }
            else {
                two++;
            }
            curr = curr.next;
        }
        
        // Reset current pointer to head for second pass
        curr = head;
        
        // Second pass: overwrite data with sorted values
        while(curr != null) {
            // Fill with 0s first
            if(zero != 0) {
                curr.data = 0;
                zero--;
            }
            // Then fill with 1s
            else if(one != 0) {
                curr.data = 1;
                one--;
            }
            // Finally fill with 2s
            else if(two != 0) {
                curr.data = 2;
                two--;
            }
            curr = curr.next;
        }
        
        return head;
    }
}
