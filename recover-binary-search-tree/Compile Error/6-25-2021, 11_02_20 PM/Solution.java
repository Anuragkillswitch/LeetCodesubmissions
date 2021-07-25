// https://leetcode.com/problems/recover-binary-search-tree

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
    TreeNode first=null;
    TreeNode second=null;
    TreeNode prev=new TreeNode(Integer.MIN_VALUE);
    public void recoverTree(TreeNode root) {
        inOrder(root);
        int temp=first.val;
        first.val=second.val;
        second.val=temp;
        
    }
    private void inOrder(TreeNode root)
    {
        if(root==null)
            return;
        
        inOrder(root.left);
        
        
        
        if(first==null && prev.val>root.val)
            first=prev.val;
        
         if(first!=null && prev.val>root.val)
            second=prev.val;
        
        prev=root;
        
        inOrder(root.right);
    }
}