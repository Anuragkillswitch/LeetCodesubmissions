// https://leetcode.com/problems/find-the-town-judge



int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {
    if (trustRowSize < N - 1)
        return -1;
    int *a=calloc(N+1,sizeof(int));
    int *b=calloc(N+1,sizeof(int));
    
    for (int i=0;i<trustRowSize;i++) {
            a[trust[i][0]] ++;
            b[trust[i][1]] ++;
    }

    for (int i = 1; i <= N; i++) {
        if (a[i] == 0 && b[i] == N - 1)
            return i;
    }
    return -1;
}