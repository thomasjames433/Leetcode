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
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode*temp,*newnode,*head1,*tail1;
    head1=tail1=NULL;
    temp=head->next;
    while(temp!=NULL){

        newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=0;
        newnode->next=NULL;
        if(head1==NULL){
            head1=tail1=newnode;
        }
        else
        tail1->next=newnode;
        
        
        while(temp->val!=0){           
            newnode->val+=temp->val;
            temp=temp->next;
        }
        tail1=newnode;
        temp=temp->next;
    }
    return head1;
}