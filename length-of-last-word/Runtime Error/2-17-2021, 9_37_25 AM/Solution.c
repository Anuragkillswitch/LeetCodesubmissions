// https://leetcode.com/problems/length-of-last-word


#include<string.h>
int lengthOfLastWord(char * s){
 int l=strlen(s);
    int i=l-1;
    int length=0;
    while(1)
    {
        if(s[i]==' ')
            break;
        length++;
        i--;
    }
    
    return length;
}