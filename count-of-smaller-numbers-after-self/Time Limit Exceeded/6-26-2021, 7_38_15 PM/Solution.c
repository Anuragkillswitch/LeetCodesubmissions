// https://leetcode.com/problems/count-of-smaller-numbers-after-self

struct btree
{
    int value;
    int lcount;
    int fcount;
    struct btree *left;
    struct btree *right;
};
struct btree * initNode(int value, int lcount,int fcount){
    //printf("value=%d,count=%d\n",value,count);
    struct btree *pNode;

    pNode=(struct btree *)malloc(sizeof(struct btree));
    pNode->value=value;
    pNode->left=NULL;
    pNode->right=NULL;
    pNode->lcount=lcount;
    pNode->fcount=fcount;
    return pNode;
}
int insertTree(struct btree *pTree,int num)
{
    struct btree *p,*f,*pNode,*maxNode;
    maxNode=NULL;
    int count=0;
    p=pTree;
    printf("num=%d\n",num);
    while(p)
    {
        f=p;
        if(num<=(p->value))
        {
            p->lcount++;
            //printf("value=%d,count=%d,k=%d\n",p->value,p->count,p->k);
            p=p->left;
        }
        else
        {
            maxNode=p;
            p=p->right;
        }
        if(p&&maxNode)
            p->fcount=maxNode->lcount+maxNode->fcount+1;
    }
    if(maxNode)
        count=maxNode->lcount+maxNode->fcount+1;
    //printf("f->value=%d,f->lcount=%d,f->fcount=%d\n\n",f->value,f->lcount,f->fcount);
    pNode=initNode(num,0,count);
    if(num>(f->value))
        f->right=pNode;
    else
        f->left=pNode;
    return count;
}
int* countSmaller(int* nums, int numsSize, int* returnSize)
{
    struct btree *pHead;
    int *counts;
    int i;
    counts=(int *)malloc(numsSize*sizeof(int));
    counts[numsSize-1]=0;
    pHead=initNode(nums[numsSize-1],0,0);
    for(i=numsSize-2;i>=0;i--)
        counts[i]=insertTree(pHead,nums[i]);
    *returnSize=numsSize;
    return counts;
}