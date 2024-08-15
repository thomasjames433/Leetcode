/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || (head!=NULL && head->next==NULL))
    return head;
    struct ListNode *tail;
    tail=head;
    while(tail!=NULL && tail->next!=NULL){
        int x= tail->val;
        tail->val= tail->next->val;
        tail->next->val=x;
        tail=tail->next->next;
    }
    return head;

}