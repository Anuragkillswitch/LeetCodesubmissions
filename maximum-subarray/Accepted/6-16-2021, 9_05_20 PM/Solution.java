// https://leetcode.com/problems/maximum-subarray

class Solution {
    public int maxSubArray(int[] nums) {
        int maximum=nums[0];
        
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i-1]>0)
                nums[i]+=nums[i-1];
            maximum=Math.max(nums[i],maximum);
        }
        return maximum;
    }
}