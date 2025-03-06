/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** list, int n) {
    struct ListNode*head,*temp;
    head=NULL;

    if(n==0)
        return NULL;
    
    while(1){
        int min=0;
        while(!list[min]){
            min++;
            if(min>=n)
                return head;
        }
        for(int i=0;i<n;i++){
            if(list[i]){
                if(list[i]->val<list[min]->val)
                    min=i;
            }
        }
        if(!head){
            head=list[min];
            list[min]=list[min]->next;
            temp=head;
        }
        else{
            temp->next=list[min];
            list[min]=list[min]->next;
            temp=temp->next;
        }
    }
    return head;
}