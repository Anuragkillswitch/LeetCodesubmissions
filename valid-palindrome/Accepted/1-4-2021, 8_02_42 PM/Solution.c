// https://leetcode.com/problems/valid-palindrome

#include<string.h>

bool isPalindrome(char * s){

  int head, tail;
head=0;
tail=strlen(s)-1;
while (head<tail) {
    if (isupper(s[head])) s[head] += 'a'-'A'; // force to lowercase
    if (isupper(s[tail])) s[tail] += 'a'-'A'; // force to lowercase
    if (!isalpha(s[head])&&!isdigit(s[head])) head++; // skip non alphanums
      else if (!isalpha(s[tail])&&!isdigit(s[tail])) tail--; // ditto
             else if (s[head++]!=s[tail--]) return false;
}
return true;  // If we've not dropped out, yet exhausted the string, ok!
}