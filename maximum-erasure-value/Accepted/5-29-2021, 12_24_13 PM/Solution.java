// https://leetcode.com/problems/maximum-erasure-value

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        HashSet<Integer> set=new HashSet<>();
        
        int i=0,j=0,max=0,sum=0;
        
        while(i<nums.length && j<nums.length)
        {
            if(!set.contains(nums[j]))
            {
                sum+=nums[j];
                
                max=Math.max(max,sum);
                set.add(nums[j]);
                j++;
            }else
            {
                sum-=nums[i];
                set.remove(nums[i]);
                
                i++;
            }
        }
        return max;
    }
}