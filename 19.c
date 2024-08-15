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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp,*temp1;
    temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    };
    temp=head;
    printf("%d",len);
    if(n==len){
        head=head->next;
        free(temp);
        return head;
    }
    else{
        len=len-n;
        int i=0;
        while(i!=len-1){
            temp=temp->next;
            i++;
        };
        temp1=temp->next;
        temp->next=temp->next->next;
        free(temp1);
        return head;
    }
}