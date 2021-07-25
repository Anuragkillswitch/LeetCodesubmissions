// https://leetcode.com/problems/deepest-leaves-sum

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
    
    //Level order traversal e last level er sum...
    //BFS
    public int deepestLeavesSum(TreeNode root) {
        
        int levelSum=0;
        
        Queue<TreeNode> queue=new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty())
        {
            levelSum=0;  //Resetting level sum back to zero for every level
            int size=queue.size();
            for(int i=0;i<size;i++)
            {
                TreeNode currentNode=queue.poll();
                levelSum+=currentNode.val;
                if(currentNode.left!=null)
                   queue.offer(currentNode.left);
                if(currentNode.right!=null)
                   queue.offer(currentNode.right);
            }
        }
        
        
        return levelSum;
        
    }
}