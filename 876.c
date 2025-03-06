/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow,*fast;
    slow=head;
    fast=head;
    while(fast->next){
        slow=slow->next;
        fast=fast->next;
        if(fast->next)
            fast=fast->next;
        else
            return slow;
    }
    return slow;
}