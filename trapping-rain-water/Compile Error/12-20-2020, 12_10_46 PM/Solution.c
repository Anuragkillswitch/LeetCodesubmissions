// https://leetcode.com/problems/trapping-rain-water



int trap(int* height, int heightSize){
 int unitSum = 0;
    int sum = 0;
    int top = 0;
    for(int i = 0; i < size; i++)
    {
        //in case of re-calculating in the next section;
        if(top < hArray[i]) //collect only the higher bar;
        {
            sum += unitSum;
            unitSum = 0;
            top = hArray[i];
        }
        else
            unitSum += top - hArray[i];
    }
    top=0, unitSum=0; //reset;
    for(int j = size - 1; j > -1; j--)
    {
        if(top <= hArray[j]) //collect both the equal and higher bar;
        {
            sum += unitSum;
            unitSum = 0;
            top = hArray[j];
        }
        else
            unitSum += top - hArray[j];
    }
    return sum;
}