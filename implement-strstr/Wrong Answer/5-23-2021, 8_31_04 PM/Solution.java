// https://leetcode.com/problems/implement-strstr

class Solution {
    public int strStr(String haystack, String needle) {
        for(int i=0;i<haystack.length();i++)
        {
            if(haystack.charAt(i)==needle.charAt(0))
            {
                return i;
            }
        }
        return -1;
    }
}