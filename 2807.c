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
int GCD(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }

    return a;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode *newnode,*mid;
    mid=head;
    while(head->next!=NULL){
        newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->next=NULL;
        newnode->val=GCD(head->val,head->next->val);
        newnode->next=head->next;
        head->next=newnode;
        head=head->next->next;
    }

    return mid;
}