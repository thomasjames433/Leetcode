/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode **list=(struct ListNode **)malloc(10000*sizeof(struct ListNode*));
    struct ListNode *temp;
    temp=head;
    int x=0;
    while(temp!=NULL){
        int i=0;
        while(i<x){
            if(temp==list[i])
                return true;
            i++;
        }
        list[x]=temp;
        x++;
        temp=temp->next;
    }
    return false;
}