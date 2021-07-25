// https://leetcode.com/problems/path-sum-ii

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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
      List<List<Integer>> paths=new ArrayList<>();
        
        findPaths(root,targetSum,new ArrayList<Integer>(),paths);
        
           //new ArrayList is the current path we are taking
        
        return paths;
    }
    
    private void findPaths(TreeNode root,int targetSum,List<Integer> currentPath,List<List<Integer>> paths)
    {
        if(root==null)
        {
            return;
        }
        
        currentPath.add(root.val);
        if(root.val==targetSum && root.left==null && root.right==null)
        {
            paths.add(currentPath);
            return;
        }
        
        findPaths(root.left,targetSum-root.val,new ArrayList<Integer>(currentPath),paths);
        
        findPaths(root.right,targetSum-root.val,new ArrayList<Integer>(currentPath),paths);
    }
}