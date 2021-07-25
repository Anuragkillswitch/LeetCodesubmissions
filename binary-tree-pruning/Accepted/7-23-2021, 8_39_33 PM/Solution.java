// https://leetcode.com/problems/binary-tree-pruning

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
    public TreeNode pruneTree(TreeNode root) {
        return containsOne(root)?root:null;
    }
    
    private boolean containsOne(TreeNode root){
        if(root==null)return false;
        boolean leftContainsOne=containsOne(root.left);
        boolean rightContainsOne=containsOne(root.right);
        
        if(!leftContainsOne)root.left=null;
        if(!rightContainsOne)root.right=null;
        
        return root.val==1 || leftContainsOne || rightContainsOne;
    }
}