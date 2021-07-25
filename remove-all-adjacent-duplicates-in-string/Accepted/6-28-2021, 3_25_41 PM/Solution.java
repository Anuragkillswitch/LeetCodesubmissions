// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
    public String removeDuplicates(String s) {
        Stack <Character> stack = new Stack ();
        for (char c : s.toCharArray ()) {
            if (!stack.isEmpty () && stack.peek () == c) {
                stack.pop ();
                continue;
            }
            stack.push (c);
        }
        StringBuilder res = new StringBuilder ("");
        while (!stack.isEmpty ())
            res.append (stack.pop());
        return res.reverse().toString();
    }
}