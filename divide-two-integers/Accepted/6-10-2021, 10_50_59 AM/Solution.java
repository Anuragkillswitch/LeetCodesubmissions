// https://leetcode.com/problems/divide-two-integers

class Solution {
    public int divide(int dividend, int divisor) {
         // quotient  overflows the range in both cases
        if (dividend == 1<<31 && divisor == -1) return Integer.MAX_VALUE;
        
        //get the sign of the values
        boolean sign = (dividend >= 0) == (divisor >= 0) ? true : false;
        
        //get normalized dividend and the divisor
        divisor = Math.abs(divisor);
        dividend = Math.abs(dividend);
        
        //result to return
        int res = 0;
        
        //----------------------------------
        //TLE for 2147483647, 1, 11 / 989 test cases passed
        // int temp1 = Math.abs(divisor);
        // int temp2 = Math.abs(dividend);
        // while (temp1 <= temp2){
        //    temp1 += Math.abs(divisor);
        //    res++;
        // }
        //----------------------------------
        
        // shift operation is same as multiplication by 2
        // make use of the shift operation by doubling and check if the divisor goes through dividend
        while (dividend - divisor >= 0){
            int count = 0;
            //divisor << 1 - keep doubling the divisor each time and increment the counter
            while (dividend - (divisor << 1 << count) >= 0) count++;    
            //update the result
            res += 1 << count;
            //update the dividend
            dividend = dividend - (divisor << count);
        }
        
        //return if sign
        return sign == true ? res : -res; 
    }  
}