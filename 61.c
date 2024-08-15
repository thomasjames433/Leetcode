/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head== NULL || head->next==NULL || k==0)
    return head;
    struct ListNode *temp,*tail;
    temp=head;
    tail=head;
    int a=0;
    while(tail->next!=NULL){
        a++;
        tail=tail->next;
    }
    a++;
    k=k%a;
    if(k==0)
    return head;

    tail->next=head;
    for(int i=0;i<a-k-1;i++){
        temp=temp->next;
    }
    head=temp->next;
    temp->next=NULL;
    return head;
    
}

Method without using temp (same logic)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head== NULL || head->next==NULL || k==0)
    return head;
    struct ListNode *tail;
    tail=head;
    int a=0;
    while(tail->next!=NULL){
        a++;
        tail=tail->next;
    }
    a++;
    k=k%a;
    if(k==0)
    return head;
    tail->next=head;
    tail=head;
    for(int i=0;i<a-k-1;i++){
        tail=tail->next;
    }
    head=tail->next;
    tail->next=NULL;
    return head;
    
}