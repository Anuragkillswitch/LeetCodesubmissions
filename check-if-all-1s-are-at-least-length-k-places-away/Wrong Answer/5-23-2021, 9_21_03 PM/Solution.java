// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
    
    public boolean kLengthApart(int[] nums, int k) {
        int pos=-1;
        for(int i=0;i<nums.length;i++)
         {
            
            if(nums[i]==1)
               { pos=i;break;}
           
         }
        for(int i=pos+1;i<nums.length;i++)
        {
            if(nums[i]==1)
            {
                if(i-pos-1<k)
                    return false;
             }
        }
        
        return true;
    }
}