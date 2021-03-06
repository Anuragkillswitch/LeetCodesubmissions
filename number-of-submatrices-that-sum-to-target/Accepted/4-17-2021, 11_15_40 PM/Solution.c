// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target


int numSubmatrixSumTarget(int** matrix, int msize, int* matrixColSize, int target){
    int rsize = matrixColSize[0];
    int dp[rsize];
    int ans = 0;
    int y = 0;

    while(y < msize){

        memset(dp, 0,  sizeof(int) * rsize); 

        for(int row = y; row < msize; row++){
            for(int col = 0; col < rsize; col++){
                // Add current column to dp.
                dp[col] += matrix[row][col];
            } 

            for (int col = 0; col < rsize; col++){
                // Start at first column and move to last column.
                int sum = 0;
                for (int _col = col; _col < rsize; _col++){
                    // Sum up columns and check if equal to target.
                    sum += dp[_col];
                    if (sum == target) ans++;
                }
            }
        } 
        y++;
    } 

    return ans;
}