/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left==right)
    return head;
    struct ListNode* temp,*tail;
    temp=head;
    int i;
    for( i=2;i<=left;i++)
    temp=temp->next;
    tail=temp; 
    int A[right-left+1];
    while(i<right+2){
        A[i-left-1]=tail->val;
        tail=tail->next;
        i++;
    }

    while(left<=right){
        temp->val=A[right-left];
        printf("%d ",temp->val);
        temp=temp->next;
        left++;
    };
    return head;

}   