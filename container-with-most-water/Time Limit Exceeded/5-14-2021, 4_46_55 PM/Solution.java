// https://leetcode.com/problems/container-with-most-water

class Solution {
    public int maxArea(int[] height) {
        int max=Integer.MIN_VALUE;
        for(int i=0;i<height.length-1;i++)
        {
            for(int j=i+1;j<height.length;j++)
            {
                int min=Math.min(height[i],height[j]);
                max=Math.max(max,min*(j-i));
            }
            
        }
        return max;
    }
}