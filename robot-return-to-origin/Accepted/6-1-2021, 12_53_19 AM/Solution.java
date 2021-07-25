// https://leetcode.com/problems/robot-return-to-origin

class Solution {
    public boolean judgeCircle(String moves) {
        int i=0;
        int j=0;
        
        for(char c : moves.toCharArray())
        {
            if(c=='R')
                 j++;
            else if(c=='L')
                 j--;
            else if(c=='U')
                 i--;
            else
                i++;
        }
        
        return (i==0 && j==0);
    }
}