// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        if(nums1.length>nums2.length)return findMedianSortedArrays(nums2,nums1);
        
        int lengthA=nums1.length;
        int lengthB=nums2.length;
        int low=0;
        int high=lengthA; //Shorter array ,We are gonna do the binary search on
        
        while(low<=high)
        {
            int partitionA=low+(high-low)/2;
            int partitionB=((lengthA+lengthB+1)/2)-partitionA;
            
            int MaxLeftA=partitionA==0?Integer.MIN_VALUE:nums1[partitionA-1];
            int MinRightA=partitionA==lengthA?Integer.MAX_VALUE:nums1[partitionA];
            
            int MaxLeftB=partitionB==0?Integer.MIN_VALUE:nums2[partitionB-1];
            int MinRightB=partitionB==lengthB?Integer.MAX_VALUE:nums2[partitionB];
            
            if(MaxLeftA<=MinRightB && MaxLeftB<=MinRightA)
            {
                if((lengthA+lengthB)%2==0)
                {
                    return (double)((Math.max(MaxLeftA,MaxLeftB)+Math.min(MinRightA,MinRightB))/2);
                    
                    
                }else{
                    return (double)(Math.max(MaxLeftA,MaxLeftB));
                }
            }else if(MaxLeftA>MinRightB)
            {
                high=partitionA-1;
                
            }else
            {
                low=partitionA+1;
            }
            
            
        }
        
        throw new IllegalArgumentException();
        
    }
}