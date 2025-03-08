/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head)
        return 0;
    struct ListNode*slow,*fast;
    slow=head;
    fast=head->next;
    while(fast){
        if(slow==fast)
            return 1;
        slow=slow->next;
        fast=fast->next;
        if(fast)
            fast=fast->next;
        else
            return 0;
        
    }
    return 0;
}