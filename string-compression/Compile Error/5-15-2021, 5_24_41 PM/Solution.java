// https://leetcode.com/problems/string-compression

class Solution {
    public int compress(char[] chars) {
        
    
        char prev=chars[0];
        int count=0;
        StringBuilder bopa=new StringBuilder();
        
       for(int i=0;i<chars.length;i++)
       {
           if(chars[i]!=prev)
           {
               if(count==1)
                 bopa.append(chars[i]);
               else
               {
                   bopa.append(chars[i]);
                   bopa.append(count);
               }  
               
               prev=chars[i];
               count=1;//The letter is already at the index i
           }else
               count++;
           
        } 
        
               if(count==1)       //Last character jeta
                 bopa.append(chars[i]);
               else
               {
                   bopa.append(chars[i]);
                   bopa.append(count);
               } 
        int index=0;
        for(char c : bopa)
        {
            
            chars[index++]=c;
        }
        
        
        return bopa.length();
    }
}