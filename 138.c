/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

 void createnode(struct Node *temp) {
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->val = temp->val;
    new->next = temp->next;
    new->random = NULL;
    temp->next = new;
}

struct Node* copyRandomList(struct Node* head) {
    if (!head)
        return NULL;

    struct Node*temp=head;
    struct Node*new;
    while(temp){
        createnode(temp);
        temp=temp->next->next;
    }

    
    temp=head;
    while(temp){
        if(temp->random)
            temp->next->random=temp->random->next;
        temp=temp->next->next;
    }


    temp=head;
    struct Node*head1=head->next;
    new=head->next;

    while(temp){
        if(temp->next){
            temp->next=temp->next->next;
            
        }else{
            temp->next=NULL;
        }

        if(new->next){
            new->next=new->next->next;
        }
        else
            new->next=NULL;
        
        temp=temp->next;
        new=new->next;
    }


    return head1;
}