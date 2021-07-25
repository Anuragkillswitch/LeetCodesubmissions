// https://leetcode.com/problems/linked-list-in-binary-tree

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        if(root==null)
            return false; //If the list is null 
        
        if(Match(head,root)) return true;
        
        return dfs(head,root.left) || dfs(head,root.right);
    }
    
    
//     private boolean dfs(ListNode head,TreeNode root)
//     {
//         if(root==null)
//             return false; //If the list is null 
        
//         if(Match(head,root)) return true;
        
//         return dfs(head,root.left) || dfs(head,root.right);
        
        
//     }
    
    private boolean Match(ListNode head,TreeNode root)
    {
        if(head==null)
            return true;
        if(root==null || root.val!=head.val)
            return false;
        
        return Match(head.next,root.left) || Match(head.next,root.right);
    }
}