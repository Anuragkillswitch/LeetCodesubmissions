// https://leetcode.com/problems/third-maximum-number

int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= first)
        {
            if (nums[i] != first)
            {
                third = second;
                second = first;
                first = nums[i];
            }
        }
        else if (nums[i] >= second)
        {
            if (nums[i] != second)
            {
                third = second;
                second = nums[i];
                printf("second: %d\n", first);
            }
        }
        else if (nums[i] >= third)
        {
            if (nums[i] != third)
            {
                third = nums[i]; 
            }
        }
    }
    return third > LONG_MIN ? third : first;
}