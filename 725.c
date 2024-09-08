/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* rs) {
    struct ListNode*temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    *rs=k;
    struct ListNode** ret=(struct ListNode**)malloc(k*sizeof(struct ListNode*));
    for(int j=0;j<k;j++)
        ret[j]=NULL;
    if(len==0)
        return ret;
        
    int x=len/k;
    if(x==0)
        k=len;
    int r=len%k;

    temp=head;int i=0;
    while(temp){
        ret[i]=temp;
        for(int j=1;j<x;j++){
            if(!temp)
            break;
            temp=temp->next;
                
        }
        if(r>0){
            temp=temp->next;
            r--;
        }
        i++;
        if(!temp)
        break;
        struct ListNode *abc=temp->next;
        temp->next=NULL;
        temp=abc;
        
    }
    
    return ret;
}