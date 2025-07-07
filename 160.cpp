/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0;
        ListNode*temp=headA;
        while(temp){
            len1++;
            temp=temp->next;
        }
        int len2=0;
        temp=headB;
        while(temp){
            len2++;
            temp=temp->next;
        }
        while(len1>len2){
            headA=headA->next;
            len1--;
        }

        while(len2>len1){
            headB=headB->next;
            len2--;
        }
        while(headA && headB && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    while(headA){
        struct ListNode*temp=headB;
        while(temp){
            if(headA==temp)
                return headA;
            temp=temp->next;
        }

        headA=headA->next;
    }
    return NULL;
}