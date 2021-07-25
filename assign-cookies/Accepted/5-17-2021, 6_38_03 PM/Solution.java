// https://leetcode.com/problems/assign-cookies

class Solution {
    public int findContentChildren(int[] g, int[] s) {
     //greedy question
        
        int contentChildren=0;
        
        Arrays.sort(g);
        Arrays.sort(s);
        int largestCookieIndex=s.length-1;
        int greediestChildIndex=g.length-1;
        
        while(largestCookieIndex>=0 && greediestChildIndex>=0)
        {
            if(s[largestCookieIndex]>=g[greediestChildIndex])
            { contentChildren++;
              largestCookieIndex--;
              greediestChildIndex--;
            }else{
                greediestChildIndex--;
            }
            
        }
        
        return contentChildren;
        
        
    }
}