/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {

    if(head==NULL || head->next==NULL)
    return head;
    struct ListNode* temp;
    temp=head;
    
    int A[200];
    int c=0;
    while(temp!=NULL){
        if(temp->val<x){
            A[c]=temp->val;
            c++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->val>=x){
            A[c]=temp->val;
            c++;
        }
        temp=temp->next;
    }
    
    temp=head;
    for(int i=0;i<c;i++){
        temp->val=A[i];
        temp=temp->next;
    }
    return head;

}