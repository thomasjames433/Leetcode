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
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(k==1)
    return head;
    struct ListNode *temp,*tail,*mem;
    temp=head;
    int len=0;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    };
    temp=head;
    mem=head;
    for(int i=1;i<=len-len%k;i+=k){
        int x=0;
        int y=k-1;
        if(mem!=head)
        temp=mem->next;
        
        
        tail=temp;
        for(int m=0;m<y;m++)
        tail=tail->next;
        mem=tail;
        while(x<y){       

            int m=temp->val;
            temp->val=tail->val;
            tail->val=m;

            x++;y--;

            if(x<y){
            temp=temp->next;
            tail=temp;
            for(m=0;m<y-x;m++)
            tail=tail->next;
            }
        }
    }
    return head;
}