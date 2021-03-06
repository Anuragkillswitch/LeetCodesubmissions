// https://leetcode.com/problems/reverse-linked-list

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        
        head->next = NULL;
        return rest;
    }
};
Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* prev = NULL, *temp, *curr = head;
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};