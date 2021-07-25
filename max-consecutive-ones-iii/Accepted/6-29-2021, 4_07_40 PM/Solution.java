// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
    
    public int longestOnes(int[] nums, int k) {
        
        
        int n = nums.length;
        
        int i = 0, j = 0, count = 0, Max1 = 0;
        
        // Check for all elements from index j : 0 to n-1
        
        while (j < n) {
            
            // If current element 0, increment count
            
            if (nums[j] == 0) {
                count++;
            }
            
            j++;   // check for next element

            
            while (i < j && count > k) {
                
                if (nums[i] == 0) {
                    count--;  
                }
                
                i++;
                
            }
            
            
            int currMax1 = j - i;    
            
            Max1 = Math.max(Max1, currMax1);
            
        }
        
        return Max1;
        
    }
}