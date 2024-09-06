/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* num, int numsize, struct ListNode* head) {
    bool A[100000+1];
    for(int i=0;i<=100000;i++)
        A[i]=0;
    for(int i=0;i<numsize;i++)
        A[num[i]]=1;
    struct ListNode*temp=head;struct ListNode*temp1=NULL;
    while(temp->next!=NULL){
        if(A[temp->val]==1){
            temp->val=temp->next->val;
            temp->next=temp->next->next;
        }
        else{
            if(temp1==NULL)
                temp1=head;
            else 
                temp1=temp1->next;
            temp=temp->next;
        }
    }
    if(temp1 && A[temp1->next->val]==1)
        temp1->next=NULL;
    printf("%d",A[2]);
    if(temp==head && A[temp->val]==1)
        return NULL;
    return head;
}