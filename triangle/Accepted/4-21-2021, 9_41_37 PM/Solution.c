// https://leetcode.com/problems/triangle

int minimumTotal(int** tri, int row, int* cols){
 for(int i = row -2 ; i >= 0 ; i--)
        for(int c = 0; c < cols[i]; c++)
            tri[i][c] += tri[i+1][c] < tri[i+1][c+1]?tri[i+1][c] : tri[i+1][c+1];
    return tri[0][0];
}