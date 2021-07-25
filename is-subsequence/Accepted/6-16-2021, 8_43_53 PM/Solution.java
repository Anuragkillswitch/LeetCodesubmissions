// https://leetcode.com/problems/is-subsequence

class Solution {
    public boolean isSubsequence(String s, String t) {
      int n = s.length();
        int m = t.length();
        int j=0;
        for(int i=0;i<m;i++){
            if(j<n && s.charAt(j)== t.charAt(i)){
                j++;
            }
        }
        if(j==n) return true;
        else return false;
    }
}