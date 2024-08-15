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
  
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    if(l1==NULL)
    return l2;
    else if(l2==NULL)
    return l1;
    else{
        struct ListNode *head,*tail,*newnode;
        head=tail=NULL;
        while(l1!=NULL && l2!=NULL){
            newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->next=NULL;
            if(head==NULL)
            head=tail=newnode;
            
            if(l1->val<=l2->val){
                newnode->val=l1->val;
                l1=l1->next;
            }
            else{
                newnode->val=l2->val;
                l2=l2->next;
            }
            tail->next=newnode;
            tail=tail->next;
        }
        if(l1!=NULL && l2==NULL){
            tail->next=l1;
        }
        else if(l1==NULL && l2!=NULL){
            tail->next=l2;
        }
        return head;
    }
}