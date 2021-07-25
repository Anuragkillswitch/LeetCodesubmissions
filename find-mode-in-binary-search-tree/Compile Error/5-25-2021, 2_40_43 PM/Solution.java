// https://leetcode.com/problems/find-mode-in-binary-search-tree

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
    Integer prev=null;
    int count=1;
    int max=0; //Maximum node frequency
    public int[] findMode(TreeNode root) {
        List<Integer> modes=new ArrayList<>();
        
        traverse(root,modes);
        
        
        int[] result=new int[modes.size()];
        
        for(int i=0;i<modes.size();i++)
        {
            result[i]=modes.get(i);
            
        }
        
        return result;
    }
    
    //Inorder Traversal Recursive
    private void traverse(TreeNode root,List<Integer> modes)
    {
        if(root==null)
             return;
        
        traverse(root.left,modes);
        
        if(prev!=null)
        {if(prev==node.val)
            count++;
         else
             count=1;
        }
        
        if(count>max)
            {max=count;
             modes.clear();
             modes.add(root.val);
            }else if(count==max)
        {
            modes.add(root.val);
        }
        
        prev=root.val;
        
        traverse(root.right,modes);
    }
}