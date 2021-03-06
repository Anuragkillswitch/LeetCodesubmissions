// https://leetcode.com/problems/combination-sum-iv

int compare(const int* a,const int* b){
    return *(int*) a - *(int*) b;
}
int combinationSum4(int* nums, int n, int target){
    if(target==0)
        return 1;
    if(n==0)
        return 0;
    qsort(nums,n,sizeof(int),compare);
    unsigned long long *dp=(unsigned long long*)calloc(target+1,sizeof(unsigned long long));
    dp[0]=1;
    
    for(int i=1;i<=target;i++){
        for(int j=0;j < n && nums[j] <=i;j++){
            dp[i]+=dp[i-nums[j]];
        }
    }
    return dp[target];
}