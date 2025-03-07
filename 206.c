/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head)
        return head;
    struct ListNode *prev,*cur,*next;
    prev=NULL;
    cur=head;
    next=head;
    while(cur->next){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    cur->next=prev;
    return cur;
}