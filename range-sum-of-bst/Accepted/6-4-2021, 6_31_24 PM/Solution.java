// https://leetcode.com/problems/range-sum-of-bst

class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        if (low <= root.val && root.val <= high)
            return root.val + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);
        else if (root.val > high) return rangeSumBST(root.left, low, high);
        else return rangeSumBST(root.right, low, high);
    }
    
}