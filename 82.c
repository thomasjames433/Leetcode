/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
    return head;

    struct ListNode *a,*c;
    a=head;
    c=head->next;

    while(head->next==c){
        
        if(c->val==a->val){
            while(c->val==a->val){
                if(c->next==NULL)
                return NULL;
                c=c->next;
            }
            
            if(c->next==NULL)
            return c;

            a=head=c;
            c=head->next;       
        }
        else{
            c=c->next;
        }
    }

 
    while(c!=NULL){
        if(a->next->val==c->val){
            while(c->val==a->next->val){
                if(c->next==NULL){
                    a->next=NULL;
                    return head;
                }
                c=c->next;
            }
            a->next=c;
            if(c->next==NULL){
                return head;
            }
            c=c->next;
        }
        else{
            a=a->next;
            c=c->next;
        }

    }


    return head;
}