// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0)return 0; 
         int prev=nums[0];
        int k=1;
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]!=prev)
            {
                nums[k++]=nums[i];
                prev=nums[i];
            }else{
                continue;
            }
        }
        
        return k;
    }
}