// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    public void flatten(TreeNode root) {
        if(root==null) return;
        
        Stack<TreeNode> stack=new Stack();
        stack.push(root);
        
        while(!stack.isEmpty())
        {
            TreeNode currentNode=stack.pop();
            
            if(currentNode.left!=null)
                stack.push(currentNode.left);
            if(currentNode.right!=null)
                stack.push(currentNode.right);
            
            if(!stack.isEmpty())
            {
                currentNode.right=stack.peek();
            }
            
            currentNode.left=null;
        }
        return;
    }
}