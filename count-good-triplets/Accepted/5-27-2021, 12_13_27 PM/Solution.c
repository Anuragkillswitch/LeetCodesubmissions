// https://leetcode.com/problems/count-good-triplets



int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
 int i,j,k,nTrip=0,diffA, diffB, diffC;
    for(i=0;i<arrSize-2;i++)
        for(j=i+1;j<arrSize-1;j++)
            for(k=j+1;k<arrSize;k++){
                diffA = abs(arr[i]-arr[j]);
                diffB = abs(arr[j]-arr[k]);
                diffC = abs(arr[i]-arr[k]);
                if(diffA<=a && diffB<=b && diffC<=c)
                    nTrip++;
            }
    return nTrip;
}