// https://leetcode.com/problems/move-zeroes

class Solution {
    public void moveZeroes(int[] nums) {
        int k=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]!=0)
                nums[index++]=nums[i];
        }
        for(int i=index;i<nums.length;i++)
        {
            nums[i]=0;
        }
    }
}