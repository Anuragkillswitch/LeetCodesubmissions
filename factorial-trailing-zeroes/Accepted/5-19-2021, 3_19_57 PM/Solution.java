// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
    public int trailingZeroes(int n) {
        int count=0;
        for(int i=5;n/i>=1;i*=5) //Factorial number of zeroes
        {
            count+=n/i;
        }
        return count;
    }
}