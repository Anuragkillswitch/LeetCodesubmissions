// https://leetcode.com/problems/find-the-town-judge



int findJudge(int N, int** trust, int trustSize, int* trustColSize){
   int candidate = -1;
    
    // define a boolean array to find non-existent trust[i][0] and use it as a candidate for judge
    bool arr[N+1];
    for(int i=0; i<=N; i++){
        arr[i] = false;
    }
    for(int i=0; i<trustSize; i++){
        arr[trust[i][0]] = true;
    }
    for(int i=1; i<=N; i++){
        if(!arr[i]){
            candidate = i;
            break;
        }
    }
    if(candidate==-1) return -1;
    
    // reuse the array to check if there not exists trust[i][1] equal to candidate
    for(int i=1; i<=N; i++){
        arr[i] = false;
    }
    for(int i=0; i<trustSize; i++){
        if(trust[i][1]==candidate) arr[trust[i][0]] = true;
    }
    
    bool res = true;
    for(int i=1; i<=N; i++){
        if(i==candidate) continue;
        res &= arr[i];
    }
    return res ? candidate : -1;
}