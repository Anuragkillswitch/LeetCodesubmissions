// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
         Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);
        int maxunits = 0;
        for (int[] box : boxTypes) 
        {
            if (truckSize >= box[0]) 
            {
                maxunits += box[0] * box[1];
                truckSize -= box[0];
            }
            else 
            {
                maxunits += truckSize * box[1];
                return maxunits;
            }
        }
        return maxunits;
    }
}