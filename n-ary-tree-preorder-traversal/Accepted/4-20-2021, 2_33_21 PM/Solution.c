// https://leetcode.com/problems/n-ary-tree-preorder-traversal

int idx;

void dfs(struct Node* root, int *A){
    if(!root) return;
    A[idx++]=root->val;
    for(int i=0; i<root->numChildren; i++)
        dfs(root->children[i], A);
}
int* preorder(struct Node* root, int* returnSize) {
    int *A = (int*)malloc(10000*sizeof(int));
    idx=0;
    dfs(root, A);
    *returnSize = idx;
    return A;
}