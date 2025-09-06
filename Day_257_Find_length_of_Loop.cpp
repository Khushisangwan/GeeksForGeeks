

/*
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}
*/

class Solution {
    // Function to find the length of a loop in the linked list.
    public int countNodesinLoop(Node head) {
        // code here.
          Map<Node,Integer> hm=new HashMap<>();
        int len=1;
        Node curr=head;
        while(curr!=null){
            if(hm.containsKey(curr)) return len-hm.get(curr);
            hm.put(curr,len);
            len++;
            curr=curr.next;
        }
        return 0;
    }
}