// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length==0) return null;
        return ConstructTreeFromArray(nums,0,nums.length-1);
    }
    
    private TreeNode ConstructTreeFromArray(int[] nums,int left,int right)
    {
        if(left>right)
            return null;
        
        int midpoint=left+(right-left)/2;
        
        TreeNode node=new TreeNode(nums[midpoint]); //Root element created;
        node.left=ConstructTreeFromArray(nums,left,midpoint-1);
        node.right=ConstructTreeFromArray(nums,midpoint+1,right);
        return node;
        
    }
}