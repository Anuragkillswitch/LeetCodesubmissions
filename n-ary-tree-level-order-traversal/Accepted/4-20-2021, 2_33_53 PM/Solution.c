// https://leetcode.com/problems/n-ary-tree-level-order-traversal

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int **a = malloc(sizeof(int *[512])), *c = *returnColumnSizes = malloc(sizeof(int [512])), k = 0, f = 0, b = 1, lb, i, l;
    for (struct Node *n[10000] = { root }, **p ; root && f < b ; k++)
        for (a[k] = malloc(sizeof(int [c[k] = (lb = b) - f])), i = 0 ; f < lb ; f++)
            for (a[k][i++] = n[f]->val, l = n[f]->numChildren, p = n[f]->children ; l-- ; n[b++] = *p++);
    return *returnSize = k, a;
}