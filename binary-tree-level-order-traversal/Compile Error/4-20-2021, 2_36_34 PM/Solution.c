// https://leetcode.com/problems/binary-tree-level-order-traversal

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(root==NULL){
        * returnSize=0;
        columnSizes[0]=(int*)calloc(1,sizeof(int));
        columnSizes[0][0]=0;
        return (int**)malloc(sizeof(int*));
    }
    struct Node** array=(struct Node**)malloc(SIZE*sizeof(struct Node*));
    array[0]=(struct Node*)malloc(sizeof(struct Node));
    array[0]->level=0;
    array[0]->val=root;
    int left=0;
    int right=1;
    int maxDepth=0;
    while(left!=right){
        if(array[left]->val->left){
            array[right]=(struct Node*)malloc(sizeof(struct Node));
            array[right]->val=array[left]->val->left;
            array[right]->level=array[left]->level+1;
            if(maxDepth<array[right]->level){
                maxDepth=array[right]->level;
            }
            right++;
        }
        if(array[left]->val->right){
            array[right]=(struct Node*)malloc(sizeof(struct Node));
            array[right]->val=array[left]->val->right;
            array[right]->level=array[left]->level+1;
            if(maxDepth<array[right]->level){
                maxDepth=array[right]->level;
            }
            right++;
        }
        left++;
    }
    int **ret_array=(int**)malloc((maxDepth+1)*sizeof(int*));
    *returnSize=0;
    for(int i=0;i<maxDepth+1;i++){
        ret_array[i]=(int*)malloc(right*sizeof(int));
    }
    columnSizes[0]=(int*)calloc(SIZE,sizeof(int));
    for(int i=0;i<right;i++){
        ret_array[array[i]->level][columnSizes[0][array[i]->level]]=array[i]->val->val;
        columnSizes[0][array[i]->level]++;
        if(*returnSize<array[i]->level+1){
            *returnSize=array[i]->level+1;
        }
    }
    return ret_array;
}