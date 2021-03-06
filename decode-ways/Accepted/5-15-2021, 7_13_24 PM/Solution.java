// https://leetcode.com/problems/decode-ways

class Solution {
    public int numDecodings(String s) {
        int[] dp=new int[s.length()+1];
        
         dp[0]=1; //No number then 1 way to decode it = Nothing
        
         dp[1]=s.charAt(0)=='0'? 0 : 1;
        
        if(dp[1]==0)
            return 0;
        
        for(int i=2;i<=s.length();i++)
        {
            int oneDigit=Integer.valueOf(s.substring(i-1,i));
            int twoDigit=Integer.valueOf(s.substring(i-2,i));
            
            if(oneDigit>=1)
            {
                dp[i]+=dp[i-1];
            }
            if(twoDigit>=10 && twoDigit<=26)
                dp[i]+=dp[i-2];
        }
        return dp[s.length()];
    }
}