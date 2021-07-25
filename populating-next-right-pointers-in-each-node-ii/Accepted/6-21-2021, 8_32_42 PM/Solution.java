// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root==null)return root;
        
        Node head=root;
        
        while(head!=null)
        {
            Node dummy=new Node(0);
            Node temp=dummy;
            
            while(head!=null)
            {
                if(head.left!=null)
                {
                    dummy.next=head.left;
                    dummy=dummy.next;
                }
                if(head.right!=null)
                {
                    dummy.next=head.right;
                    dummy=dummy.next;
                }
                head=head.next;
            }
            head=temp.next;
        }
        
        return root;
        
    }
}