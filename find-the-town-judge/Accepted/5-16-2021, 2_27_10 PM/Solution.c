// https://leetcode.com/problems/find-the-town-judge



int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int hs[10000+1]={0}; int i,j;
    for(i=0;i<trustSize;hs[trust[i][1]]++,hs[trust[i][0]]--,i++);
    for(j=1;j<N+1;j++) if(hs[j]==N-1) return j;
    return -1;
}