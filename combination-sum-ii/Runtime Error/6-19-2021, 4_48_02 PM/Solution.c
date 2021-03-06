// https://leetcode.com/problems/combination-sum-ii

void dfs(int* nums, int* colSizes, int numsSize, int target, 
         int** sols, int* sols_size, int* sol, int sol_size, int pointer) {
  if(target < 0) return;
  else if(target == 0) {
    sols[*sols_size] = calloc(sol_size, sizeof(int));
    for(int i = 0; i < sol_size; i++) sols[*sols_size][i] = sol[i];
    colSizes[*sols_size] = sol_size;
    (*sols_size)++;
  }
  else{
    for(int i = pointer; i < numsSize; i++) {
      if(nums[i] > target) return;
      // Avoid duplicates
      if(i != pointer && nums[i] == nums[i - 1]) continue;
      sol[sol_size] = nums[i];
      // The reason we do not need to make a copy is DFS guarantees that we will
      // NOT stop searching on current path unless it gets accepted or rejected
      dfs(nums, colSizes, numsSize, target - nums[i], 
          sols, sols_size, sol, sol_size + 1, i + 1);
    }
  }
}

int comp(const void* v1, const void* v2) {
  return (*(int*) v1) - (*(int*) v2);
}

int** combinationSum2(int* nums, int numsSize, int target, int** colSizes, int* returnSize) {
  // Use an unbounded array (amortized constant time) to replace the following 500 calloc
  // if you want to make it more rigorous
  int** sols = calloc(500, sizeof(int*));
  *colSizes = calloc(500, sizeof(int));
  int* sol = calloc(500, sizeof(int));
  qsort((void*) nums, numsSize, sizeof(int), comp);
  dfs(nums, *colSizes, numsSize, target, sols, returnSize, sol, 0, 0);
  return sols;
}