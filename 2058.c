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
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnsize) {
    *returnsize=2;
    int *ret=(int*)malloc(2*sizeof(int));
    ret[0]=-1;
    ret[1]=-1;
    if(head->next->next==NULL)
    return ret;
    struct ListNode *temp;
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    
    temp=head;
    int A[count];
    A[1]=-1;
    int i=0;
    count=0;
    while(temp!=NULL){
        int a=temp->val;
        temp=temp->next;
        count++;
        if(temp->next==NULL)
        break;

        if((temp->val<a && temp->val<temp->next->val) || (temp->val>a && temp->val>temp->next->val)){
            A[i]=count;
            i++;
        }
    }
    
    if(A[1]==-1){
    return ret;}
    
    ret[1]=ret[0]=A[i-1]-A[0];
    
    for(count=1;count<i;count++){
        if(A[count]-A[count-1]<ret[0])
        ret[0]=A[count]-A[count-1];
        if(A[count]-A[count-1]==1)
        break;
    }
    return ret;
}

