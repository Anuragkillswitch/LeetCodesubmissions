// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
    int start=0, end=0, len=0;
    char c[];
    public String longestPalindrome(String s) {
        c=s.toCharArray();
        for(int x=1; x<c.length-(end-start)/2; x++) {     //condition to stopp extra 
            find(x-1,x);                                  //for type 1
            find(x-1,x+1);                                //for type 2
        }
        return new String(c, start, end-start+1);
    }
    void find(int x, int y) {
        while(x>=0 && y<c.length) {
            if(c[x]!=c[y])
                break;
            --x;
            ++y;
        }
        ++x;--y;
        if(end-start>=y-x)
            return;
        start=x;
        end=y;
    }
}