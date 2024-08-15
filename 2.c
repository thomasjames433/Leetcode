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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
   
    struct ListNode *newnode,*head,*tail;
    int sum=0;
    int carry=0;
    head=NULL;
    tail=NULL;
    while(l1!=NULL && l2!=NULL ){
        newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->next = NULL;
        sum=0;
        if (head==NULL){
            head=tail=newnode;
            sum= l1->val+l2->val;
            carry=sum/10;
            newnode->val=sum%10;
            l1=l1->next;
            l2=l2->next;
        }
        else{       
            tail->next=newnode;
            sum= l1->val+l2->val+carry;
            carry=sum/10;
            newnode->val=sum%10;
            tail=newnode;
            l1=l1->next;
            l2=l2->next;
        }
    }
    
    if (l1!=NULL &&l2==NULL){
        while(l1!=NULL){
            newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
                    newnode->next = NULL;

            tail->next=newnode;
            sum=l1->val+carry;
            newnode->val=sum%10;
            tail=newnode;
            carry=sum/10;
            l1=l1->next;
        }
    }
    if (l1==NULL &&l2!=NULL){
        while(l2!=NULL){
            newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
                    newnode->next = NULL;

            tail->next=newnode;
            sum=l2->val+carry;
            newnode->val=sum%10;          
            tail=newnode;    
            carry=sum/10;
            l2=l2->next;
        }
    }
    if(l1==NULL && l2==NULL && carry==1){
        newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
                newnode->next = NULL;

        tail->next=newnode;
        newnode->val=1;
        tail=newnode;
    }

    return head;
}