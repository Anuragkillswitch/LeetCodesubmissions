// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
    public int search(int[] nums, int target) {
        int index=0;
        for(int i=0;i<nums.length;i++)
            {if(nums[i]==target){index=i;break;}}
        
        return index;
    }
}