// https://leetcode.com/problems/number-of-days-between-two-dates

class Solution {
    public int daysBetweenDates(String date1, String date2) {
        String[] d1 = date1.split("-");
        String[] d2 = date2.split("-");
        
        int[] id1 = {Integer.valueOf(d1[0]), Integer.valueOf(d1[1]), Integer.valueOf(d1[2])};
        int[] id2 = {Integer.valueOf(d2[0]), Integer.valueOf(d2[1]), Integer.valueOf(d2[2])};
        
        int[][] m2d = {{-1, 
                      31,28,31,30,31,30,31,
                      31,30,31,30,31},
                     {-1, 
                      31,29,31,30,31,30,31,
                      31,30,31,30,31}};
        
        long days1 = 0;
        long days2 = 0;
        
        //Year
        for(int i = 1971; i < id1[0]; i++)
            days1 += leap(i) == 1 ? 366 : 365;
        
        for(int i = 1971; i < id2[0]; i++)
            days2 += leap(i) == 1 ? 366 : 365;
        
        //Month
        int leap1 = leap(id1[0]);
        int leap2 = leap(id2[0]);
        
        for(int i = 1; i < id1[1]; i++)
            days1 += m2d[leap1][i]; 
        
        for(int i = 1; i < id2[1]; i++)
            days2 += m2d[leap2][i]; 
        
        
        //Day
        days1 += id1[2];
        days2 += id2[2];
        
        return (int)Math.abs(days1 - days2);
    }
    
    private int leap (int year){
        if(year % 4 != 0 )
            return 0;
        else if(year % 100 != 0)
            return 1;
        else if(year % 400 != 0)
            return 0;
        else
            return 1;
    }
}