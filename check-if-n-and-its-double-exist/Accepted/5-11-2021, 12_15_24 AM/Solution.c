// https://leetcode.com/problems/check-if-n-and-its-double-exist



bool checkIfExist(int* arr, int arrSize){
    for(int i=0;i<arrSize-1;i++)
    {
        for(int j=i+1;j<arrSize;j++)
        {
            if(arr[i]==2*arr[j] || arr[j]==2*arr[i])
                return true;
        }
    }
    return false;
}