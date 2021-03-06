// https://leetcode.com/problems/binary-tree-right-side-view

int count_right(struct TreeNode* root) {
    if(root==NULL) {
        return 0;
    }
    return(count_right(root->left)+1+count_right(root->right));
}

void populate_right(struct TreeNode* root,int *a,int *index,int level) {
    if(root==NULL) {
        return;
    }
    
    if (level == *index) {
        a[(*index)++] = root->val;
    }

    populate_right(root->right,a,index,level+1);
    populate_right(root->left,a,index,level+1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){
    int c,index=0,level=0;
    int *res;
    c = count_right(root);
    res = (int *)malloc(sizeof(int)*c);
    memset(res,0,sizeof(int)*c);
    
    populate_right(root,res,&index,level);
    *returnSize = index;
    return res;
}