// https://leetcode.com/problems/merge-two-sorted-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
struct ListNode *a=NULL,*temp;
if(l1==NULL)
   return l2;
if(l2==NULL)
   return l1;
if(l1->val<=l2->val)
{
a=l1;
l1=l1->next;
}
else
{
a=l2;
l2=l2->next;
}
temp=a;
while(l1!=NULL && l2!=NULL)
{
if(l1->val<=l2->val)
{
a->next=l1;
a=l1;
l1=l1->next;
}
else
{
a->next=l2;
a=l2;
l2=l2->next;
}
}
while(l1!=NULL)
{
a->next=l1;
a=l1;
l1=l1->next;
}
while(l2!=NULL)
{
a->next=l2;
a=l2;
l2=l2->next;
}
return temp;  
}