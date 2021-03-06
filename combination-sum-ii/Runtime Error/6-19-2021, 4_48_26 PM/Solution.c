// https://leetcode.com/problems/combination-sum-ii

void sort(int* nums, int begin, int end)
{
    int l=begin, r=end;
    int v = nums[l+(r-l)/2];
    while(l <= r)
    {
        while(nums[l] < v) l++;
        while(nums[r] > v) r--;
        if(l <= r)
        {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            l++;
            r--;
        }
    }
    if(begin < r)
        sort(nums, begin, r);
    if(l < end)
        sort(nums, l, end);
}

void helper(int* nums, int size, int start, int target, int* stack, int top, int*** arr, int** colSizes, int* returnSize)
{
    if(target == 0) //valid set, just collect;
    {
        *returnSize += 1;
        *colSizes = (int*)realloc(*colSizes, sizeof(int)*(*returnSize));
        (*colSizes)[*returnSize-1] = top+1;
        *arr = (int**)realloc(*arr, sizeof(int*)*(*returnSize));
        (*arr)[*returnSize-1] = (int*)malloc(sizeof(int)*(top+1));
        for(int i = 0; i <= top; i++)
            (*arr)[*returnSize-1][i] = stack[i];
        return ;
    }
    for(int i = start; i < size; i++)
    {
        if(nums[i] > target) break; //no need to check further;
        if(i==start || nums[i]!=nums[i-1]) //only different candidates can be allowed in each traversing level for further traversal;
        {
            stack[top+1] = nums[i];
            helper(nums, size, i+1, target-nums[i], stack, top+1, arr, colSizes, returnSize); //check the next element;
        }
    }
}

//AC - 4ms;
int** combinationSum2(int* nums, int size, int target, int** colSizes, int* returnSize)
{
    sort(nums, 0, size-1);
    int** arr = (int**)malloc(sizeof(int*));
    *returnSize = 0;
    int* stack = (int*)malloc(sizeof(int)*(target/nums[0]+1));
    int top = -1;
    helper(nums, size, 0, target, stack, top, &arr, colSizes, returnSize);
    return arr;
}