// https://leetcode.com/problems/reverse-integer

class Solution {
    public int reverse(int num) {
        boolean negative=false;
        
        if(num<0)
        {
            negative=true;
            num*=-1;
        }
        
        long reversed =0;
        while(num>0)
        {
            reversed=(reversed*10)+(num%10);
            num/=10;
        }
        if(reversed>Integer.MAX_VALUE) //Integer overflow condition
            return 0; 
        
        return negative? (int)(-1*reversed) : (int)reversed;
    }
}